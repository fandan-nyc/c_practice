#include <stdio.h> 

struct point {
	int x ; 
	int y;
};

struct screen {
	struct point leftDown;
	struct point rightUp;
};

struct point createPoint(int x, int y){
	struct point p; 
	p.x = x;
	p.y = y;
	return p;
}


int getArea(struct screen s){
	int bread = s.rightUp.x - s.leftDown.x;
	int height = s.rightUp.y - s.leftDown.y;
	return bread * height;
}

struct screen createScreen(struct point leftDown, struct point rightUp){
	struct screen s; 
	s.leftDown=leftDown;
	s.rightUp=rightUp;
	return s;
}

void printPoint(struct point p){
	printf("x: %d\n",p.x);
	printf("y: %d\n",p.y);
}

int ptInRect(struct point p, struct screen a){
	return p.x >= a.leftDown.x && p.x <=a.rightUp.x && p.y >=a.leftDown.y && p.y <= a.rightUp.y;
}



int main(int argc, char ** argv){
	struct point p = createPoint(1,2);
	printPoint(p);
	struct point q = createPoint(3,4);
	struct screen s = createScreen(p,q);
	int area = getArea(s);
	printf("the area is %d\n",area);
	printf("check if a point is in an area\n");
	int check = ptInRect(p,s);
	if(check == 0)
		printf("not in the area\n");
	else
		printf("in the area\n");
}