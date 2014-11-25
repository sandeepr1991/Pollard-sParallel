
 
#include <stdio.h>
#include<stdlib.h>
#include<gmp.h>
//#include<conio.h>
#ifdef _OPENMP
#include <omp.h>
#define TRUE  1
#define FALSE 0
#else	/* 
 */
#define omp_get_thread_num() 0
#endif	/* 
 */
  mpz_t num, f1;

mpz_t factor[100]; // Array to store generated factors

int a = 0,flg=0;

void
GCD (mpz_t m, mpz_t n) 
{
  
mpz_t n1, zero, mod;
  
mpz_init (n1);
  
mpz_init (mod);
  
mpz_init (zero);
  
mpz_set (n1, n);
  
mpz_set_str (zero, "0", 0);
  
while (mpz_cmp (n1, zero) != 0)
    
    {
      
mpz_mod (mod, m, n1);
      
mpz_set (m, n1);
      
mpz_set (n1, mod);
    
}

}




/*void GCD( mpz_t m, mpz_t n)
{
  mpz_t n1, zero;
  mpz_init(n1);
 mpz_set(n1,n);
  mpz_set_str(zero,"0",0);
  if((mpz_cmp(m,zero))==0) return;
  while(( mpz_cmp(m,n1))!=0) // execute loop until m == n
{
  if( (mpz_cmp(m,n1))>0)
  //m= m - n; // large - small , store the results in large variable
    mpz_sub(m,m,n1);
    else
      //n= n - m;
        mpz_sub(n1,n1,m);
        }
          //return ( m); // m or n is GCD
   //         mpz_out_str(stdout,10,m);
   }*/ 
  

void
f (mpz_t n, mpz_t x, mpz_t c) 
{
  
mpz_mul (x, x, x);
  
mpz_add (x, x, c);
  
mpz_mod (x, x, n);
  

//      return ((x*x+c)% n);
} 
void

polrho (mpz_t n, mpz_t c) 
{
  

int  d = 1;

mpz_t x, y, x1, y1, count1, count;
  
mpz_init (count);
mpz_init (count1);
mpz_init (x);
  
mpz_init (y);
  
mpz_init (x1);
  
mpz_init (y1);
  
mpz_set_str (y1, "1", 0);
  
mpz_set_str (x, "2", 0);
  
mpz_set_str (y, "2", 0);
  
mpz_set_str (x1, "1", 0);

mpz_set_str (count, "0", 0);

mpz_set_str (count1, "500000", 0);

while ((mpz_cmp (x1, y1)) == 0 && a != 1 && (mpz_cmp(count,count1))!=0)
    
    {
      
	mpz_add(count,count,y1);

#pragma omp critical
	
f (n, x, c);
      
#pragma omp critical
	//  y = f(f(y,c),c);
	f (n, y, c);
      
f (n, y, c);
      
	//  mpz_out_str(stdout,10,x); printf("********");
	//  mpz_out_str(stdout,10,y);
	//   mpz_out_str(stdout,10,x1);       
	//      printf("x=%d,y=%d\n",x,y);
	//if(x==x1 && y==y1)
	

//count++;
      
	//getch();
//#pragma omp critical
	
mpz_sub (x1, x, y);
      
mpz_abs (x1, x1);
      
	//   mpz_out_str(stdout,10,x1);printf("!!!!!!!!!!!!\n");
	GCD (x1, n);
      
	// mpz_out_str(stdout,10,x1); printf("GCD");      
    }
  
if (a == 1)
    
    {
      
a = 0;
      
printf ("Thread %d has been forced to change N value",
	       omp_get_thread_num ());
      
return;
      
	//n=f1;
	//polrho(f1,c);
    }
  
if ((mpz_cmp (x1, n)) == 0 || (mpz_cmp(count,count1))==0)
    mpz_set_str (x1, "1", 0);
  
  else
    {
      
a = 1;
      
	// printf("***************%d",sizeof(mpz_t));
	printf ("\n Answer from thread %d: ", omp_get_thread_num ());
      
mpz_out_str (stdout, 10, x1);
    


}
#pragma omp critical
{
	if( (mpz_cmp(f1,y1))==0)
	   {
		   mpz_set (f1, x1);
           
	}
}
// changing N
    fflush (stdout);
  
printf ("\n \n");
  
    //exit(0);
    //    mpz_out_str(stdout,10,n);
}






void
cric () 
{
  
printf ("Thread %d trying to enter critical section\n ",
	   omp_get_thread_num ());
  
#pragma omp critical
    printf ("In cric():critcal section executed by %d\n",
	    omp_get_thread_num ());

} 
void

funcA (mpz_t num) 
{
  
int sol;
  
mpz_t c;
  
mpz_init (c);
  
mpz_set_str (c, "1", 0);
  
//        printf("In funcA: this section is executed by thread %d\n",
    //  omp_get_thread_num());
    //      cric();
    //   printf("Thread %d came out of critical section\n",omp_get_thread_num());
    polrho (num, c);
  
    /* if(sol==1) {
       printf("No solution from thread %d\n",omp_get_thread_num());
       return;
       }
       printf("Thread %d: And answer = %d and %d\n",omp_get_thread_num(),sol,n/sol); */ 
} 
void

funcE (mpz_t num) 
{
  
int sol;
  
mpz_t c;
  
mpz_init (c);
  
mpz_set_str (c, "3", 0);
  
    //printf("In funcE: this section is executed by thread %d\n",
    //omp_get_thread_num());
    //polrho(25,2);
    //   cric();
    //printf("Thread %d came out of critical section\n",omp_get_thread_num());
    //       sleep(2);
    polrho (num, c);
  
    /*        if(sol==1) {
       printf("No solution from thread %d\n",omp_get_thread_num());
       return;
       }
       printf("Thread %d: And answer = %d and %d\n",omp_get_thread_num(),sol,n/sol); */ 

} 
void

funcB () 
{
  
printf ("In funcB: this section is executed by thread %d\n",
	   
omp_get_thread_num ());

} 

void

funcC (mpz_t num) 
{
  
mpz_t c;
  
mpz_init (c);
  
mpz_set_str (c, "5", 0);
  
    //printf("In funcE: this section is executed by thread %d\n",
    //omp_get_thread_num());
    //polrho(25,2);
    //   cric();
    //printf("Thread %d came out of critical section\n",omp_get_thread_num());
    //       sleep(2);
    polrho (num, c);



} 

void

funcD (mpz_t num) 
{
mpz_t c;
  
mpz_init (c);
  
mpz_set_str (c, "4", 0);
  
    //printf("In funcE: this section is executed by thread %d\n",
    //omp_get_thread_num());
    //polrho(25,2);
    //   cric();
    //printf("Thread %d came out of critical section\n",omp_get_thread_num());
    //       sleep(2);
    polrho (num, c);
  

} 
int
main () 
{
  
mpz_t one, temp, zero;

mpz_init(zero);
  
mpz_init (one);
  
mpz_init (temp);
  
mpz_init (f1);
  

#ifdef _OPENMP
    (void) omp_set_dynamic (FALSE);
  
if (omp_get_dynamic ())
    {
      printf ("Warning: dynamic adjustment of threads has been set\n");
    }
  
(void) omp_set_num_threads (2);
  
#endif	/* 
 */
    mpz_init (num);
  
mpz_set_str (zero,"0",0);
mpz_set_str (one, "1", 0);
  
mpz_set_str (num, "368", 0);	//12348187//8876044532898802067
  int i, j,k,flag=0;
 
for (i = 0; i < 100; i++)
{    
  mpz_init (factor[i]);
  mpz_set_str(factor[i],"1",0);
}
i = 0;
  j = 0;
  
  do        // the loop runs for finding factors of factors
    
    {
      mpz_set_str(f1,"1",0);

#pragma omp parallel shared(a) 
      {
	
#pragma omp sections 
	{
	  
#pragma omp section 
	    (void) funcA (num);
	  

#pragma omp section 
	    (void) funcE (num);
	  

	    /* #pragma omp section
	       (void) funcC(num);
	       
	       
	       #pragma omp section
	       (void) funcD(num);
	       
	       
	    #pragma omp section
	       (void) funcE(); */ 
	
} /*-- End of sections block --*/ 
      
} /*-- End of parallel region --*/ 
	  flg=0;
	if ((mpz_cmp (f1, one)) != 0)
	
	{
	  
for (k = 0; k <= i; k++)
	    
	    {
	      
if ((mpz_cmp (factor[k], f1)) == 0)
		flag = 1;
	    
}
	  
if (!flag)
	    
	    {
	      
mpz_set (factor[i], f1);
	      
i++;
	    
}
	  
mpz_div (temp, num, f1);
	  
flag = 0;
	  
for (k = 0; k <= i; k++)
	    
	    {
	      

if ((mpz_cmp (factor[k], temp)) == 0)
		flag = 1;
	    
}
	  
if (!flag)
	    
	    {
	      
mpz_set (factor[i], temp);
	      
i++;
	    
}
// flag =0;	

}
      
if((mpz_cmp(factor[j],one))!=0 && (mpz_cmp(factor[j],zero)!=0))

mpz_set (num, factor[j]);
      
j++;
     
printf ("i=%d j=%d ", i, j);
      
mpz_out_str (stdout, 10, num);

for(k=0;k<5;k++)
{
	//if((mpz_cmp(factor[k],one))!=0)
 mpz_out_str(stdout,10,factor[k]);
 printf("\n");
} 
    
}
  while ((i+1)!=j);
 printf("\n\n j= %d Final answer: ",j); 
for(k=0;k<i;k++)
{
	//if((mpz_cmp(factor[k],one))!=0)
 mpz_out_str(stdout,10,factor[k]);
 printf("\n");
} 
   //getch();
    return (0);

}


  /***********************************************///////////////////////////*********************************/
  
// pollardrho.cpp : Defines the entry point for the console application.
//
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
int n=25;

//int GCD(int a,int b)
//{
//   if(b==0)
//        return a;
//   else
//        return GCD(b,a%b);
//}
 
void main()
{
	
	printf("factor=%d",polrho(n));
	getch();
}*/ 
