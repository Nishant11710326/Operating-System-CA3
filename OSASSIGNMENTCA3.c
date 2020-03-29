#include<stdio.h> 
 
int main() 
{ 
      int i, lim, t = 0, x, c = 0, t_quant,u; 
      
	  int w_t = 0, t_a_t = 0,pos,z,p[10],pri[10], a_t[10], b_t[10], tem[10],b; 
      
	  float avg_wt, avg_tat;
      
	  printf("\nEnter Total Number of Processes:"); 
      
	  scanf("%d", &lim); 
      
	  x = lim; 
      for(i = 0; i < lim; i++) 
      {
	    p[i]=i+1;
	   
	    pri[i]=0;
            printf("\nEnter total Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &a_t[i]);
            printf("Burst Time:\t");
            scanf("%d", &b_t[i]); 
            tem[i] = b_t[i];
      }
	   
      printf("\nEnter the Time Quantum:"); 
      scanf("%d", &t_quant); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t pririty\n");
      for(t = 0, i = 0; x != 0;) 
      { 

		    for(z=0;z<lim;z++)
		    {
			int tem1;
			pos=z;
			for(u=z+1;u<lim;u++)
			{
			    if(pri[u]<pri[pos])
				pos=u;
			}
		 
		tem1=pri[z];
	
		pri[z]=pri[pos];
	
		pri[pos]=tem1;
		 
			tem1=b_t[z];
			b_t[z]=b_t[pos];
			b_t[pos]=tem1;
		 			tem1=a_t[z];
				a_t[z]=a_t[pos];
			a_t[pos]=tem1;

			tem1=p[z];
				p[z]=p[pos];
			p[pos]=tem1;

			tem1=tem[z];
				tem[z]=tem[pos];
			tem[pos]=tem1;
		    }
		{
		}
            
			if(tem[i] <= t_quant && tem[i] > 0) 
            { 
                  t = t + tem[i]; 
                  tem[i] = 0; 
                  c = 1; 
            } 
            
			else if(tem[i] > 0) 
            { 
                  tem[i] = tem[i] - t_quant; 
                  t = t + t_quant; 
            } 

	for(b=0;b<lim;b++)
		{
			if(b==i)
			pri[b]+=1;
			else
			pri[b]+=2;
		}

            if(tem[i] == 0 && c == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[i], b_t[i], t - a_t[i], t - a_t[i] - b_t[i],pri[i]);
                  w_t = w_t + t - a_t[i] - b_t[i]; 
                  t_a_t = t_a_t + t - a_t[i]; 
                  c = 0; 
            } 
            if(i == lim - 1) 
            {
                  i = 0; 
            
			}
            else if(a_t[i + 1] <= t) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      return 0; 
}
