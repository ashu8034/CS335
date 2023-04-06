target:
	flex df.l
	bison -d ast.ypp
	g++ lex.yy.c ast.tab.cpp -o ast