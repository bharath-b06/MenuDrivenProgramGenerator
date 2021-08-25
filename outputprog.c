#include <stdio.h>

void fn_one()
{
    printf("one\n");
}
void fn_oneone()
{
    printf("oneone\n");
}
void fn_onetwo()
{
    printf("onetwo\n");
}
void fn_onetwothree()
{
    printf("onetwothree\n");
}
void fn_onethree()
{
    printf("onethree\n");
}
void fn_two()
{
    printf("two\n");
}
void fn_aaa()
{
    printf("aaa\n");
}
void fn_xxx()
{
    printf("xxx\n");
}
void fn_zzz()
{
    printf("zzz\n");
}
void fn_yyy()
{
    printf("yyy\n");
}
void fn_bbb()
{
    printf("bbb\n");
}
void fn_ccc()
{
    printf("ccc\n");
}
void fn_three()
{
    printf("three\n");
}
void fn_abc()
{
    printf("abc\n");
}
void fn_pqr()
{
    printf("pqr\n");
}
void fn_ppp()
{
    printf("ppp\n");
}
void fn_qqq()
{
    printf("qqq\n");
}
void fn_rrr()
{
    printf("rrr\n");
}
void fn_four()
{
    printf("four\n");
}
void fn_five()
{
    printf("five\n");
}
int main()
{
	int opt;
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_one();
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_oneone();
				break;
			case 2 : 
				fn_onetwo();
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_onetwothree();
				break;
		}
		scanf("%d", &opt);
	}
				break;
			case 3 : 
				fn_onethree();
				break;
		}
		scanf("%d", &opt);
	}
				break;
			case 2 : 
				fn_two();
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_aaa();
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_xxx();
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_zzz();
				break;
		}
		scanf("%d", &opt);
	}
				break;
			case 2 : 
				fn_yyy();
				break;
		}
		scanf("%d", &opt);
	}
				break;
			case 2 : 
				fn_bbb();
				break;
			case 3 : 
				fn_ccc();
				break;
		}
		scanf("%d", &opt);
	}
				break;
			case 3 : 
				fn_three();
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_abc();
				break;
			case 2 : 
				fn_pqr();
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_ppp();
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : 
				fn_qqq();
				break;
		}
		scanf("%d", &opt);
	}
				break;
		}
		scanf("%d", &opt);
	}
				break;
			case 3 : 
				fn_rrr();
				break;
		}
		scanf("%d", &opt);
	}
				break;
			case 4 : 
				fn_four();
				break;
			case 5 : 
				fn_five();
				break;
		}
		scanf("%d", &opt);
	}
}
