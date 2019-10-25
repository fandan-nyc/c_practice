#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 100
#define MAX_ROW 10

struct Address {
	int id;
	int set;
	char name[MAX_SIZE];
	char email[MAX_SIZE];
};

struct Database {
	struct Address rows[MAX_ROW];
};

struct Conn {
	FILE * filename;
	struct Database *db;
};

void die(const char *message){
	if(errno){
		perror(message);
	}else{
		printf("%s\n", message);
	}
}

void Address_print(struct Address *addr){
	printf("%d %s %s\n", addr-> id, addr-> name, addr-> email);
}

void Database_load(struct Conn * conn){
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->filename);
	if(rc != 1){
		die("failed to load db");
	}
}

struct Conn * Database_open(const char* file_name, char mode){
	struct Conn* conn = malloc(sizeof(struct Conn));
	if(!conn){
		die("failed to start conn");
	};
	conn->db = malloc(sizeof(struct Database));
	if(!conn->db){
		die("failed to init db");
	}
	if(mode == 'C' || mode == 'c'){
		conn -> filename = fopen(file_name, "w");
	}else{
		conn -> filename = fopen(file_name, "r+");
		if(conn -> filename){
			Database_load(conn);
		}
		else{
			die("cannot load file");
		}
	}
	if (!conn->filename){
		die("failed to open file");
	}
	return conn;
}

void Database_list(struct Conn * conn){
	int i = 0 ;
	struct Database * db = conn->db;
	for(int i = 0; i < MAX_ROW; i++){
		struct Address curr = db->rows[i];
		if(curr.set){
			Address_print(&curr);
		}
	}
}

void Database_write(struct Conn *conn){
	rewind(conn->filename);
	int rc = fwrite(conn -> db, sizeof(struct Database), 1, conn->filename);
	if(rc != 1){
		die("faile to write");
	}
	rc = fflush(conn->filename);
	if(rc == -1){
		die("cannot flush the db");
	}
}

void Database_create(struct Conn * conn){
	for(int i = 0; i < MAX_ROW; i++){
		struct Address addr = {.id = i, .set=0};
		conn->db->rows[i] = addr;
	}	
}

void Database_set(struct Conn *conn, int id, const char* name, const char* email){
	struct Address *addr = &conn->db->rows[id];
	if(addr -> set){
		die("id already set");
	}
	addr->id = id;
	addr->set = 1;
	char* res = strncpy(addr->name, name, MAX_SIZE);
	if(! res){
		die("copy name failed for id" );
	}
	res = strncpy(addr->email, email, MAX_SIZE);
	if(! res){
		die("copy email failed for id");
	}
}

void Database_get(struct Conn *conn, int id){
	struct Address * addr = &conn->db->rows[id];
	if(addr->set){
		Address_print(addr);
	}else{
		die("ID not set");
	}
}

void Database_delete(struct Conn * conn, int id){
	struct Address * addr = &conn->db->rows[id];
	if(! addr->set){
		die("cannot delete, does not exist");
	}else{
		addr->set = 0;
	}
}



void Database_close(struct Conn *conn){
	if(conn){
		if(conn->filename) fclose(conn->filename);
		if(conn-> db) free(conn->db);
		free(conn);
	}
}

int main(int argc, char* argv[]){
	if(argc < 3){
		die("usage: quetion_17 <db file name> <action> [action parameters]");
	}
	char *filename = argv[1];
	char action = argv[2][0];
	struct Conn* conn = Database_open(filename, action);
	int id = 0;
	if (argc > 3){
		id = atoi(argv[3]);
	}
	if(id >= MAX_ROW){
		die("id overflow");
	}
	switch(action){
		case 'c':
		case 'C':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'G':
		case 'g':
			if(argc != 4){
				die("need id for get");
			}
			Database_get(conn, id);
			break;
		case 'S':
		case 's':
			if( argc != 6){
				die("need more args");
			}
			char* name = argv[4];
			char* email = argv[5];
			Database_set(conn, id, name, email);
			Database_write(conn);
			break;
		case 'D':
		case 'd':
			if( argc != 4 ){
				die("cannot delete");
			}
			Database_delete(conn, id);
			Database_write(conn);
			break;
		case 'l':
		case 'L':
			Database_list(conn);
			break;
		default:
			die("action not recognized");
	}
	Database_close(conn);
}
