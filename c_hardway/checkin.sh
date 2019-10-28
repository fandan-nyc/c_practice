if [ -z $1 ];
then echo "you need to specify the question number";
exit
fi	
git add -A;
git commit -m "question $1"
git push origin master

