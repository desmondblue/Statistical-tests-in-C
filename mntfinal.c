/*The Following project implements various statistical tests using C programming language
1. Linear Regression
2. Z test
3. T test*/
#include<stdio.h>
#include<stdlib.h> // input output functions
#include<conio.h>
#include<math.h> //for pow() function
/*t test

The test takes value of alpha as 0.05

T = ((sample mean - claimed mean)*square root of n)/standard deviation

*/
void compare_t(int dof, float calculated_t){
float table [32];// t from t table
FILE *myfile;
	myfile = fopen("ttable.txt","r");
	for(int i=0;i<32;i++){
		fscanf(myfile,"%4f,",&table[i]);
	}
	
	float t_table;// value of t from table
	printf("\nTaking alpha(percentile) = 0.05\n");
	if(dof==40){
		t_table = table[30];		
	}
	else if (dof==60){
		t_table = table[31];
	}
	else
		t_table = table[dof-1];
printf("\nValue of t from table : %0.02f\n",t_table);
	if(calculated_t <0){calculated_t*= (-1);}
if(t_table<0){t_table*= (-1);}

	if(t_table>calculated_t){
		printf("\nThe null hypothesis is accepted as the calculated t-value is less than the table value at an alpha level of .05. \nWhich means the p value is greater than alpha level P>0.05");
	}
	else
			printf("\nThe null hypothesis is rejected as the calculated t-value is greater than the table value at an alpha level of .05.\n Which means the p value is greater than alpha level P<0.05");
fclose(myfile);
}
void calc_t(float cm,float sm, float sd, float n){

float t = ((sm-cm)*pow(n,0.5))/sd;
printf("\nCalculated Value of t is %0.02f",t);
	int dof=n-1; //degree of freedom
compare_t(dof,t);	
}
//Z test
void compare_z(double x){
	/*This formula comes from the fact that the normal 
	distribution can be used to approximate the binomial distribution if np and n(1-p) = 5.
	*/
	double alpha = 0.0500;
	if( x<alpha){
	printf("\nThe null hypothesis is rejected as value of P according to Z is less than 0.05\n");
	}
	else
	printf("The null hypothesis is accepted as value of P according to Z is greater than 0.05\n");

getchar();
}
//function declaration
void calc_z(float p, float ps){
	
	int i,j;
	float z; // the value of z will be stored here
	//formulare for the value of z
	z = (ps-p)/pow((p*(1-p))/100,0.5);
	z = floor(100*z)/100;
printf("\nValue of z is %0.4f\n",z);
	

double ztable[70][10];
	FILE *myfile2;
	myfile2 = fopen("ztable.txt","r");
	for(int i=0;i<70;i++){
		for(j=0;j<10;j++){
		fscanf(myfile2,"%4lf,",&ztable[i][j]);
	}
	}
float index[70][10]={0.00,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.10,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.20,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29,0.30,0.31,0.32,0.33,0.34,0.35,0.36,0.37,0.38,0.39,0.40,0.41,0.42,0.43,0.44,0.45,0.46,0.47,0.48,0.49,0.50,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.60,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,0.70,0.71,0.72,0.73,0.74,0.75,0.76,0.77,0.78,0.79,0.80,0.81,0.82,0.83,0.84,0.85,0.86,0.87,0.88,0.89,0.90,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1.00,1.01,1.02,1.03,1.04,1.05,1.06,1.07,1.08,1.09,1.10,1.11,1.12,1.13,1.14,1.15,1.16,1.17,1.18,1.19,1.20,1.21,1.22,1.23,1.24,1.25,1.26,1.27,1.28,1.29,1.30,1.31,1.32,1.33,1.34,1.35,1.36,1.37,1.38,1.39,1.40,1.41,1.42,1.43,1.44,1.45,1.46,1.47,1.48,1.49,1.50,1.51,1.52,1.53,1.54,1.55,1.56,1.57,1.58,1.59,1.60,1.61,1.62,1.63,1.64,1.65,1.66,1.67,1.68,1.69,1.70,1.71,1.72,1.73,1.74,1.75,1.76,1.77,1.78,1.79,1.80,1.81,1.82,1.83,1.84,1.85,1.86,1.87,1.88,1.89,1.90,1.91,1.92,1.93,1.94,1.95,1.96,1.97,1.98,1.99,2.00,2.01,2.02,2.03,2.04,2.05,2.06,2.07,2.08,2.09,2.10,2.11,2.12,2.13,2.14,2.15,2.16,2.17,2.18,2.19,2.20,2.21,2.22,2.23,2.24,2.25,2.26,2.27,2.28,2.29,2.30,2.31,2.32,2.33,2.34,2.35,2.36,2.37,2.38,2.39,2.40,2.41,2.42,2.43,2.44,2.45,2.46,2.47,2.48,2.49,2.50,2.51,2.52,2.53,2.54,2.55,2.56,2.57,2.58,2.59,2.60,2.61,2.62,2.63,2.64,2.65,2.66,2.67,2.68,2.69,2.70,2.71,2.72,2.73,2.74,2.75,2.76,2.77,2.78,2.79,2.80,2.81,2.82,2.83,2.84,2.85,2.86,2.87,2.88,2.89,2.90,2.91,2.92,2.93,2.94,2.95,2.96,2.97,2.98,2.99,3.00,3.01,3.02,3.03,3.04,3.05,3.06,3.07,3.08,3.09,3.10,3.11,3.12,3.13,3.14,3.15,3.16,3.17,3.18,3.19,3.20,3.21,3.22,3.23,3.24,3.25,3.26,3.27,3.28,3.29,3.30,3.31,3.32,3.33,3.34,3.35,3.36,3.37,3.38,3.39,3.40,3.41,3.42,3.43,3.44,3.45,3.46,3.47,3.48,3.49,0.00,-0.01,-0.02,-0.03,-0.04,-0.05,-0.06,-0.07,-0.08,-0.09,-0.10,-0.11,-0.12,-0.13,-0.14,-0.15,-0.16,-0.17,-0.18,-0.19,-0.20,-0.21,-0.22,-0.23,-0.24,-0.25,-0.26,-0.27,-0.28,-0.29,-0.30,-0.31,-0.32,-0.33,-0.34,-0.35,-0.36,-0.37,-0.38,-0.39,-0.40,-0.41,-0.42,-0.43,-0.44,-0.45,-0.46,-0.47,-0.48,-0.49,-0.50,-0.51,-0.52,-0.53,-0.54,-0.55,-0.56,-0.57,-0.58,-0.59,-0.60,-0.61,-0.62,-0.63,-0.64,-0.65,-0.66,-0.67,-0.68,-0.69,-0.70,-0.71,-0.72,-0.73,-0.74,-0.75,-0.76,-0.77,-0.78,-0.79,-0.80,-0.81,-0.82,-0.83,-0.84,-0.85,-0.86,-0.87,-0.88,-0.89,-0.90,-0.91,-0.92,-0.93,-0.94,-0.95,-0.96,-0.97,-0.98,-0.99,-1.00,-1.01,-1.02,-1.03,-1.04,-1.05,-1.06,-1.07,-1.08,-1.09,-1.10,-1.11,-1.12,-1.13,-1.14,-1.15,-1.16,-1.17,-1.18,-1.19,-1.20,-1.21,-1.22,-1.23,-1.24,-1.25,-1.26,-1.27,-1.28,-1.29,-1.30,-1.31,-1.32,-1.33,-1.34,-1.35,-1.36,-1.37,-1.38,-1.39,-1.40,-1.41,-1.42,-1.43,-1.44,-1.45,-1.46,-1.47,-1.48,-1.49,-1.50,-1.51,-1.52,-1.53,-1.54,-1.55,-1.56,-1.57,-1.58,-1.59,-1.60,-1.61,-1.62,-1.63,-1.64,-1.65,-1.66,-1.67,-1.68,-1.69,-1.70,-1.71,-1.72,-1.73,-1.74,-1.75,-1.76,-1.77,-1.78,-1.79,-1.80,-1.81,-1.82,-1.83,-1.84,-1.85,-1.86,-1.87,-1.88,-1.89,-1.90,-1.91,-1.92,-1.93,-1.94,-1.95,-1.96,-1.97,-1.98,-1.99,-2.00,-2.01,-2.02,-2.03,-2.04,-2.05,-2.06,-2.07,-2.08,-2.09,-2.10,-2.11,-2.12,-2.13,-2.14,-2.15,-2.16,-2.17,-2.18,-2.19,-2.20,-2.21,-2.22,-2.23,-2.24,-2.25,-2.26,-2.27,-2.28,-2.29,-2.30,-2.31,-2.32,-2.33,-2.34,-2.35,-2.36,-2.37,-2.38,-2.39,-2.40,-2.41,-2.42,-2.43,-2.44,-2.45,-2.46,-2.47,-2.48,-2.49,-2.50,-2.51,-2.52,-2.53,-2.54,-2.55,-2.56,-2.57,-2.58,-2.59,-2.60,-2.61,-2.62,-2.63,-2.64,-2.65,-2.66,-2.67,-2.68,-2.69,-2.70,-2.71,-2.72,-2.73,-2.74,-2.75,-2.76,-2.77,-2.78,-2.79,-2.80,-2.81,-2.82,-2.83,-2.84,-2.85,-2.86,-2.87,-2.88,-2.89,-2.90,-2.91,-2.92,-2.93,-2.94,-2.95,-2.96,-2.97,-2.98,-2.99,-3.00,-3.01,-3.02,-3.03,-3.04,-3.05,-3.06,-3.07,-3.08,-3.09,-3.10,-3.11,-3.12,-3.13,-3.14,-3.15,-3.16,-3.17,-3.18,-3.19,-3.20,-3.21,-3.22,-3.23,-3.24,-3.25,-3.26,-3.27,-3.28,-3.29,-3.30,-3.31,-3.32,-3.33,-3.34,-3.35,-3.36,-3.37,-3.38,-3.39,-3.40,-3.41,-3.42,-3.43,-3.44,-3.45,-3.46,-3.47,-3.48,-3.49,};	
//Since z table only supports values till 3.49 to -3.49
	if(z>3.49||z<-3.49){
		compare_z(ztable[0][0]);
	}

	for( i=0;i<70;i++){
		for(j=0;j<10;j++){
		if( z == index[i][j]){
				
			compare_z(ztable[i][j]);
			}
	}
}
}
//Linear Regression
//structure declaration
struct Point
{
    double x, y;
};

//function declaration
void CalculateRegressionValues(struct Point *points, int count, double *m, double *c)
{
    double Sx = 0.0;
    double Sy = 0.0;
    double Sxx = 0.0;
    double Sxy = 0.0;
    double Syy = 0.0;

    int loop;

    for(loop = 0; loop < count; loop++)
    {
        double x = points[loop].x;
        double y = points[loop].y;

        Sx += x;
        Sy += y;
        Sxx += x*x;
        Sxy += x*y;
        Syy += y*y;
    }
	//formulae for the value of m and c
    *m = (count*Sxy - Sx*Sy) / (count*Sxx - Sx*Sx);
    *c = (Sy - (*m)*Sx) / count;

    printf("Calculated value of m = %lf and calculated value of c = %lf\n", *m, *c);
}

// Main function declaration

int main(){
Mainmenu:
    system("cls");

    struct Point points[10];
    printf("Welcome \nThe following program gives you a brief introduction and implementation of few statistical tests in C");
    printf("\n");
    printf("\nTest List \n1. Linear Regresssion\n2. Z test\n3. T test \nEnter a choice\n");
    int ch ;
    scanf("%d",&ch);
    switch (ch){
        case 1:{
            LRmenu:
                   system("cls");
            printf("\nLinear regression \n1. Introduction\n2.Implementation\nEnter a choice\n");
            int op;
            scanf("%d",&op);
                switch(op){
                    case 1:
                        printf("\nIntroduction\nIn statistics, linear regression is a linear approach for modeling the relationship between a scalar dependent variable y and one or more explanatory variables (or independent variables) denoted X. The case of one explanatory variable is called simple linear regression.");
                        printf("\nEnter 1 to go back to main menu .\nEnter 2 to go back to previous menu \n");
                        int var;
                        scanf("%d",&var);
                        switch(var){
                    case 1:
                        goto Mainmenu;
                        break;
                    case 2:
                        goto LRmenu;
                        break;
                        };
                        break;
                    case 2:

                    printf("\nImplementation of linear regression\n");
                    int count = 10;
                    int loop;
                    double x ;
                    double y;
                    double m, c;
					printf("\nEnter the number of values for X & Y \n");
					scanf("%d",&count);
					printf("\nEnter the values for X & Y\n");
					printf("\n  \tX\tY");
                    for(loop = 0; loop < count; loop++)
                            {printf("\n#%d\t",loop+1);
                                scanf("%lf",&points[loop].x);
                                scanf("%lf",&points[loop].y);
                            }
					printf(" \nSelect Dependent variable (variable to be found)\nX OR Y\n");
					char axe;
					scanf("%s",&axe);
					if(axe == 'y'|| axe == 'Y'){
					 	printf("\nEnter the value of x for which you want to find y :");
						scanf("%lf",&x);
                        CalculateRegressionValues(points, count, &m, &c);
                        y = m*x + c;
                        printf("The calculated value for x = %lf is... y = %lf\n", x, y);}
					else if(axe == 'x'|| axe == 'X'){
						printf("\nEnter the value of y for which you want to find x :");
						scanf("%lf",&y);
                        CalculateRegressionValues(points, count, &m, &c);
                        x=(y-c)/m;
                        printf("The calculated value for y = %lf is... x = %lf\n", x, y);}

                        break;
				       default: printf("invalid choice");
					
	}//End of switch bracket for linear regression
			;break;//End of linear regression case
		}case 2:
		{// Z test introduction and implementation
			ZTmenu:
			system("cls");
			printf("\nZ test\n1.Introduction\n2.Implementation\nEnter choice : ");
			int op;
			scanf("%d",&op);
			switch(op){
				case 1: system("cls");
					printf("\nIntroduction\nA z-test is a statistical test used to determine whether two population means are different when the variances are known and the sample size is large. \nThe test statistic is assumed to have a normal distribution, and nuisance parameters such as standard deviation should be known for an accurate z-test to be performed.");
					printf("\nEnter 1 to go back to main menu .\nEnter 2 to go back to previous menu\n");
                        int var;
                        scanf("%d",&var);
                        switch(var){
                    case 1:
                        goto Mainmenu;
                        break;
                    case 2:
                        goto ZTmenu;
                        break;
                        };
				break;
					case 2:
						//implementation of z test
					printf("\nEnter the population proportion claim (in percentage):");
					float p,x;
					scanf("%f",&p);
					p=p/100;
					printf("\nEnter the sample population size: ");
					float ps;
					scanf("%f",&x);
					printf("\nEnter the sample population proportion: ");
					scanf("%f",&ps);
					ps = ps/x;
					printf("\nNull Hypothesis\nH0 : P = %0.2f(if accepted signifies claim is true)\nH1 : P != %0.2f(i.e. if rejected signifies claim is false)\n",p,p);
					calc_z(p,ps);
					break;
				default: printf("\nIncorrect choice");
		};//End of switch bracket of z test
			break;}//End of Z test case
			//Start of t test
			case 3:{
            TTmenu:
                   system("cls");
						
            printf("\nT test \n1. Introduction\n2.Implementation\nEnter a choice\n");
            int op;
            scanf("%d",&op);
                switch(op){
						case 1:
				 		system("cls");
						printf("Introduction\nA t-test is an analysis of two populations means through the use of statistical examination; a t-test with two samples is commonly used with small sample sizes, testing the difference between the samples when the variances of two normal distributions are not known.\nA t-test looks at the t-statistic, the t-distribution and degrees of freedom to determine the probability of difference between populations; the test statistic in the test is known as the t-statistic");
						printf("\nEnter 1 to go back to main menu .\nEnter 2 to go back to previous menu");	
						int var;
                        scanf("%d",&var);
                        switch(var){
                    case 1:
                        goto Mainmenu;
                        break;
                    case 2:
                        goto TTmenu;
                        break;
                        };	
						break;
						case 2:{
							//implementation of t test
						float cm,sm,sd;//claimed mean, observed mean, standard deviation
							float n;
							printf("\nEnter the claimed population mean :");
							scanf("%f",&cm);
							printf("\nEnter size of sample population :");
							scanf("%f",&n);
							printf("\nEnter the sample population mean :");
							scanf("%f",&sm);
							printf("\nThe standard deviation for the sample population :");
							scanf("%f",&sd);
							printf("\nNull Hypothesis\nH0 : mean(u) =%0.2f\n H1: mean(u) != %0.2f\n",cm,cm);
							calc_t(cm,sm,sd,n);

						}
						break;
			default: printf("\nIncorrect Choice\n");};}
		
default: printf("\nIncorrect Choice\n");
};
return 0;
}

