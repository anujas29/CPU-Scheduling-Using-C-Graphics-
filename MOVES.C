# Codes-from-my-masters-Projects
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
char *help11[] = {
"            		         ---------------------  ",
"                         CPU SCHEDULING  ",
"                       ---------------------  ",
"   CPU Scheduling is the basis of multiprogrammed operating systems. By",
"switching the CPU among processes, the operating system can make the ",
"computer more productive.",
"",
"   Scheduling is a fundamental operating-system function. Almost all compu",
"-ter resources are scheduled before use.  The CPU is, ofcourse, one of the",
"primary computer resources. Thus, its scheduling is central to the ",
"operating system design.",
"",
"                      CPU Scheduler",
"                      -------------",
"   Whenever the CPU becomes idle, the operating system must select one of ",
"the processes in the ready queue to be executed. The selection process is ",
"carried by the short-term scheduler(or CPU scheduler).  The scheduler ",
"selects from among the processes in memory that are ready to execute and ",
"allocates the cpu to one of them.",
"",
"   Note that the ready queue is not necessarily a first-in, first-out",
"queue.  As we shall see when we consider the various scheduling algorithms",
"ready queue may be implemented as a FIFO queue, a priority queue, a tree, ",
"or simply an unordered linked list.  Conceptually, however, all the ",
"processes in the ready queue are lined up waiting for a chance to run on the ",
"CPU. The records in the queues are generally PCBs of the processes.",
"",
"          Dispatcher",
"          ----------",
"   Another component involved in the scheduling function is the dispatcher",
"The dispatcher is the module that gives control of the CPU to the process",
"selected by the short-term scheduler. This function involves:",
"           * Switching context",
"           * Switching to user mode",
"           * Jumping to the proper location in the user program",
"The dispatcher should be as fast as possible, given that it is invoked dur",
"-ing every process switch.",
""};
char *help123[]={
"                      Scheduling Criteria",
"                      -------------------",
"   Different CPU scheduling algorithms have different properties and may",
"favour one class of processes over another.  In choosing which algorithm ",
"to use in a particular situation, we must consider the properties of the ",
"various algorithms.",
"",
"   Many criteria have been suggested for comparing CPU scheduling algorith",
"-ms. Which characteristics are used for comparison can make a substantial ",
"difference in the determination of the best algorithm.  Criteria that are ",
"used include the following:",
"           * CPU utilization",
"           * Throughput",
"           * Turnaround time",
"           * Waiting time",
"           * Response time",
"   It's desirable to maximise CPU utilization and throughput, and to minim",
"-ise the turnaround time, waiting time, and response time. In most cases",
"we optimize the average measure.",
"   Our measure of comparison is the AVERAGE WAITING TIME."
	      };

char *help12[] = {
"                      Scheduling Algorithms",
"                      ---------------------",
"   CPU scheduling deals with the problem of deciding which of the processe",
"-s in the ready queue is to be allocated the CPU.  There are many differen",
"-t cpu scheduling algorithms.  Below, we describe several of these algorit",
"-thms ",
"",
"       First-Come, First-Served Scheduling",
"       -----------------------------------",
"   By far the simplest CPU scheduling algorithm is the first-come, first-",
"served scheduling(FCFS) algorithm.  With this scheme, the process that",
"requests the CPU first is allocated the CPU first.  The implementation of ",
"the FCFS policy is easily managed with a FIFO queue.  When a process enter",
"the ready queue, its PCB is linked onto the tail of the queue.  When the ",
"cpu is free, it is allocated to the process at the head of the queue. The",
"running process is then removed from the queue. ",
"",
"   The average waiting time under the FCFS policy, however, is often quite",
"long.",
"",
"       Shortest-Job-First Scheduling",
"       -----------------------------",
"  This algorithm associates with each process the length of the latter's ",
"next CPU burst.  When the CPU is available, it is assigned to the process",
"that has the smallest next CPU burst.  If two processes have the same ",
"length next cpu burst, FCFS scheduling is used to break the tie.",
"   The real difficulty with the SJF algorithm is knowing the length of the",
"next CPU burst.",
""};
char *help124[]={
"       Priority Scheduling",
"       -------------------",
"   Here a priority is associated with each process, and the CPU is allocat",
"-ed to the process with the highest priority.  Equal-priority processes ",
"are scheduled in FCFS order",
"",
"       Round-Robin Scheduling",
"       ----------------------",
"   The round-robin(RR) scheduling algorithm is designed especially for ",
"timesharing systems.  It is similar to FCFS scheduling, but preemption is ",
"added to switch between processes.  A small unit of time, called a time ",
"quantum or time slice, is defined. A time quantum is generally from 10 to ",
"100 milliseconds. The ready queue is treated as a circular queue. The CPU ",
"schedular goes around the ready queue, allocating the CPU to each process ",
"for a time interval of upto 1 time quantum.",
"",
"   To implement RR scheduling, we keep the ready queue as a FIFO queue of",
"processes.  New processes are added to the tail of the ready queue.  The ",
"cpu scheduler picks the first process from the ready queue, sets a timer ",
"to interrupt after 1 time quantum, and dispatches the process.",
"",
"   One of two things will then happen.  The process may have a CPU burst ",
"of less than 1 time quantum.  In this case, the process itself will ",
"release the CPU voluntarily.  The scheduler will then proceed to the next ",
"process in the ready queue.  Otherwise, if the CPU burst of the currently ",
"running process is longer than 1 time quantum, the timer will go off and ",
"will cause an interrupt to the operating system.  A context switch will ",
"be executed and the process will be put at the tail of the ready queue.  ",
"the cpu scheduler will then select the next process in the ready queue.",
"",
"  The average waiting time under the RR policy, however, is often quite ",
"long",
	      };

int draw_border();
void mov(int nop)
{
int s,l=0,w,f,g,ki=0,h,e,a=30,b=70,i,j,k,gd =DETECT,gm,c=50,co[10],p=200,q=200,r=150,t=250;
char z[10],m[5]="P";
co[0]=1;
co[1]=2;
co[2]=3;
co[3]=4;
co[4]=5;
co[5]=6;
co[6]=7;
co[7]=8;
co[8]=9;
co[9]=10;
clrscr();

initgraph(&gd,&gm,"..//bgi");
draw_border();


/* draw a rectangle */
for(i=0;i<nop;i++)
{
setfillstyle(1,4);
bar(30,a,70,b);
a=a+50;
b=b+50;
}
for(j=0;j<nop;j++)
{
setcolor(4);
s=co[j];
itoa(s,z,10);
strncat(z,m,5);
outtextxy(80,c,z);
c=c+50;
}
setcolor(6);
outtextxy(535,37,"CPU");
rectangle(498,48,602,152);
setfillstyle(6,6);
bar(500,50,600,150);
setfillstyle(1,1);
bar(550,300,600,350);
setcolor(RED);
rectangle(220,310,520,465);
setcolor(GREEN);
rectangle(223,313,517,462);
setcolor(BLUE);
outtextxy(253,325,"->Process is in waiting state");
outtextxy(253,355,"->Process is in execution state");
outtextxy(253,385,"->Process is in normal state");
outtextxy(253,415,"->Process is in completed state");
outtextxy(253,445,"->Process data pass through");

setfillstyle(1,11);
bar(230,320,255,345);
setfillstyle(1,6);
bar(230,350,255,375);
setfillstyle(1,RED);
bar(230,380,255,405);
setfillstyle(1,BLUE);
bar(230,410,255,435);
setfillstyle(1,3);
bar(230,440,255,465);

a=30;
b=70;
getch();
for(j=0;j<nop;j++)
{
setfillstyle(1,6);
bar(30,a,70,b);
a=a+50;
b=b+50;
if(ki<nop-1)
{
setfillstyle(1,11);
bar(30,a,70,b);
ki=ki+1;
}
if (l<nop)
{
setcolor(4);
s=co[l];
l=l+1;
itoa(s,z,10);
strncat(z,m,5);
outtextxy(180,270,z);
p=200;
q=200;
r=150;
t=250;
e=550;
f=170;
g=600;
h=220;
for(k=0;k<15;k++)
{
setfillstyle(1,3);
bar(p,q,r,t);
delay(100);
	sound(2000);
	delay(100);
	nosound();

setfillstyle(1,WHITE);
bar(p,q,r,t);
p=p+20;
q=q-8;
r=r+20;
t=t-8;
}
delay(500);
	sound(2000);
	delay(1000);
	nosound();
delay(500);

for(w=0;w<11;w++)
{
setfillstyle(1,3);
bar(e,f,g,h);
delay(100);
	sound(2000);
	delay(100);
	nosound();

setfillstyle(1,WHITE);
bar(e,f,g,h);
e=e;
f=f+8;
g=g;
h=h+8;
}
setcolor(WHITE);
outtextxy(180,270,z);
a=a-50;
b=b-50;
setfillstyle(1,1);
bar(30,a,70,b);
a=a+50;
b=b+50;
}
delay(1000);
}

settextstyle(1,0,1);
setcolor(BLUE);
outtextxy(470,440,"Press any key....");



getch();
}


int draw_border ()
{
cleardevice();
setbkcolor(WHITE);
setcolor(RED);
rectangle(10,10,630,470);

setcolor(GREEN);

rectangle(15,15,623,465);
return(1);
}










char ratting[5][10]={"*****","****","***","**","*"},ka[2]="P";
int nop,               /*    no of process*/
slice,                 /* quantum time slice*/
welcome(),            /* welcome screen*/

set_title(),
draw_boarder(),
disp_res(),
draw_gc(int chart[][3],int opt),
accept(),                          /*function to acceot the i/p
parameter*/

sort(int key),
input[10][3],              /*process_no+burst_tome+priority*/
sinput[10][3],             /*i/p forsjf*/
pinput[10][3],	    /*i/p array for priority*/
pipe[150],	   /*array store pipeline in rr*/
pip[150],
pipecount = 0,
pipecou=0,
perform(int key);
	/*alogrithm for */

float r_fifo = 0,r_sjf=0,r_pri = 0,r_rr=0;

void main()
{
int i , j, gd =DETECT,gm,ch,xa,ya,lines;
initgraph(&gd,&gm,"..//bgi");
welcome();
clrscr();
draw_boarder();
   xa=20;ya=40;
   lines=25;
   for(i=0;i<=lines&&i<=27;i++)
   {
      setcolor(2);
      settextstyle(0,0,1);
      outtextxy(xa,ya,help11[i]);
      ya=ya+15;
   }
getch();
clrscr();
draw_boarder();
   xa=20;ya=40;
   lines=19;
   for(i=0;i<=lines&&i<=27;i++)
   {
      setcolor(2);
      settextstyle(0,0,1);
      outtextxy(xa,ya,help123[i]);
      ya=ya+15;
   }
getch();
clrscr();
draw_boarder();
   xa=20;ya=40;
   lines=25;
   for(i=0;i<=lines&&i<=27;i++)
   {
      setcolor(2);
      settextstyle(0,0,1);
      outtextxy(xa,ya,help12[i]);
      ya=ya+15;
   }
getch();
clrscr();
draw_boarder();
   xa=20;ya=40;
   lines=27;
   for(i=0;i<=lines&&i<=27;i++)
   {
      setcolor(2);
      settextstyle(0,0,1);
      outtextxy(xa,ya,help124[i]);
      ya=ya+15;
   }
getch();
clrscr();
draw_boarder();
xa=50;
ya=100;
      setcolor(BLUE);
      settextstyle(1,0,1);
      outtextxy(xa,ya,"Now let us see how these Algorthims work!");
settextstyle(1,0,1);
setcolor(BLUE);
outtextxy(470,440,"Press any key....");

getch();

accept();
getche();
}


int welcome()
{
draw_boarder();
set_title();
settextstyle(1,0,2);
setcolor(RED);

outtextxy(230,240,"DEVEPLOPED BY....");
/*setcolor(RED);*/
settextstyle(1,0,3);
delay(1000);

setcolor(RED);
outtextxy(400,280,"ANUJA sinha");


outtextxy(425,310,"............");

settextstyle(1,0,1);
setcolor(BLUE);
outtextxy(470,440,"Press any key....");
getch();
return(1);
}

/* function to display the title */

int set_title()
{
       setcolor(BLUE);
       settextstyle(0,0,3);
	outtextxy(140,50,"C.P.U.SCHEDULING");
	line(138,71,530,71);
	line(138,75,530,75);
	return(1);
	}


/* function to draw boarder */
int draw_boarder ()
{
cleardevice();
setbkcolor(WHITE);
setcolor(RED);
rectangle(10,10,630,470);

setcolor(GREEN);

rectangle(15,15,623,465);
return(1);
}


/* function to accepting process details*/

int  accept()
{
int row ,col,x1,x2,y,i;
clearviewport();
cleardevice();
draw_boarder();
set_title();
settextstyle(2,0,5);
setcolor(RED);
outtextxy(30,95,"Enter process detail .....");
loop_nop:
setcolor(BLUE);
outtextxy(30,115," * number of n process : ");
outtextxy(34,128,"( 1 < Process < 10 )");
gotoxy(31,8);
printf("        ");
gotoxy(31,8);
fflush(stdin);
scanf("%d",&nop);
/*checking io data */
if((nop<1)||(nop >10))
{
gotoxy(32,25);
printf("invalid entry try again...");
getche();
gotoxy(32,25);
printf("                                        ");
gotoxy(31,8);
printf("    ");
goto loop_nop;
}
outtextxy(300,115,"* the slice time  : ");
outtextxy(300,128,"( Slice time > 1 )");
lop23:
gotoxy(60,8);
fflush(stdin);
scanf("%d",&slice);

/* checking the io data */
if(slice <= 0)
{
gotoxy(32,25);
printf("slice time should > 1         ");

 getche();
 gotoxy(32,25);
 printf("                                ");
 gotoxy(57,8);
 printf("                             ");
 goto lop23;
 }
 outtextxy(75,165,"*process          * burst time                   * priority ");
 setcolor(BLUE);
  outtextxy(75,177," ~~~~~~~            ~~~~~~~~~                     ~~~~~~~ ");
    x1 =17 ; y =13 ;
    gotoxy(x1,y);
    for(row = 0; row <nop ; row ++)
    {
    gotoxy(x1,y);
    printf("%d",row+1);
    input[row][0] = row +1;
    pinput[row][0] = row +1;
     sinput[row][0] = row +1;
     x2 = 36 ;
    for(col = 1; col < 3 ; col++)
    {
    gotoxy(x2,y);
    fflush(stdin);
    scanf("%d",&input[row][col]);
    sinput[row][col]= input[row][col];
    pinput[row][col]= input[row][col];
    x2 = x2 + 28 ;
    }
    y = y+ 1;
    }
      /* processing given data */
    sort(1);
    sort(2);
    mov(nop);
    for(i=1;i<=4;i++)
    perform(i);
    disp_res();
    outtextxy(470,440,"Press any key...");
    getche();
    return(1);
    }/*end of accept */


    /* function to sort io for sjf/priority */
    int sort(int key)
    {
    int row ,col ,temp,k;
    if(key==1)
    {
    for(row=0;row<nop-1;row++)
    for(col=row+1;col<nop;col++)
    if(sinput[row][key]>sinput[col][key])
    for(k=0;k<3;k++)
    {
    temp=sinput[row][k];
    sinput[row][k]=sinput[col][k];
    sinput[col][k]=temp;
    }
    }
    else
    {
     for(row=0;row<nop-1;row++)
    for(col=row+1;col<nop;col++)
    if(pinput[row][key]>pinput[col][key])
    for(k=0;k<3;k++)
    {
    temp=pinput[row][k];
    pinput[row][k]=pinput[col][k];
    pinput[col][k]=temp;
    }
    }
    return(1);
    }/*end of function*/


       /*function to perform algorithm */
int perform(int key)
{
int i,j,dummy[10],waittime[10];
int k,over=0,totwt=0;
float at=0.0;
pipecount=0;
pipecou=0;
switch(key)
{
case 1 : /* fifo*/
       for(i=nop-1;i>0;i--)
       for(j=i-1;j>=0;j--)
       at =at+input[j][1];
       r_fifo =at/nop;
       break;

case 2 :                    /* SJF*/
       for(i=nop-1;i>0;i--)
       for(j=i-1;j>=0;j--)
       at =at+sinput[j][1];
       r_sjf =at/nop;
       break;


case 3 : /* PRIORITY*/
       for(i=nop-1;i>0;i--)
       for(j=i-1;j>=0;j--)
       at =at+pinput[j][1];
       r_pri =at/nop;
       break;


  case 4 : /* R-ROBIN*/
  /*load dummy with input array */
       for(i=0;i<nop;i++)
       {
       dummy[i] =input[i][1];
       waittime[i]=0;
       }
       /*calaulating the waiting time for process */
       while(over == 0)
       {
       for(i = 0;i < nop;i++)
       if(dummy[i] != 0)
       {
       /*add process title to the pipe[]*/
      pipe[pipecount++] = i+1;
    for(k = 0;k < slice;k++)
    {
    /*decrement the burst time for current process &increment
       the waiting time for other process*/
       for(j=0;j<nop;j++)
       if(j==i)
       dummy[j]=dummy[j]-1;
       else if(dummy[j] != 0)
       waittime[j]=waittime[j]+1;
       if(dummy[i]==0)
       break;

       }
       }
       /*checking whethetr all process r completed or not ? */
       for(i=0;i<nop;i++)
	if(dummy[i]!=0)
	{
	over =0;
	break;
	}
	else
	over =1;
	}
	/*end while*/
	/*calaulating the avg waiting time */
	for(i=0;i<nop;i++)
	totwt=totwt+waittime[i];
	r_rr=(float)totwt/nop;
	break;

	}/*endof select*/
	return(1);
	}/*end of perforn*/


	/*FUNCTION TO DISPLAY RESULT*/
	disp_res()
	{
	int opt=0;
	draw_boarder();
	set_title();
	settextstyle(1,0,2);
	outtextxy(180,135,"1.FIRST IN FIRST OUT .");
	outtextxy(180,165,"2.SHORTEST JOB FIRST.");
	outtextxy(180,195,"3. PRIORITY ");
	outtextxy(180,225,"4.ROUND-ROBIN .");
	outtextxy(180,255,"5.CONCLUSION .");
	outtextxy(180,285,"6.NEWPROCESS.");
	outtextxy(180,315,"7.EXIT");
	settextstyle(2,0,5);
	outtextxy(230,363,"Enter a number [1-7] : ");
	gotoxy(55,25);
	lop:
	gotoxy(55,25);
	printf("                ");
	gotoxy(55,25);
	fflush(stdin);
	scanf("%d",&opt);
	/*checking the input data */
	if((opt < 1) || (opt > 7))
	{
	gotoxy (15 , 25);
	printf("* invalid entry,try again....");
	getche();
	gotoxy(15 , 25);
	printf("                                ");
	goto lop;
	}
	switch (opt)
	{
	case 7 :                      /* exit program */
		draw_boarder();
		set_title();
		settextstyle(1 , 0 , 4);
		setcolor(BLUE);
		outtextxy(400, 400, "thank you ");
		getche();
		exit(0);
	case 6 :              /* accepting new value */
		clearviewport();
		accept();
		break;
	case 1 :        /* fifo/rr/srjf */
	case 4 :
		draw_gc(input, opt);
		break;
	case 2 :          /*sjf */
		draw_gc(sinput, opt);
		break;
	case 3 :           /* priority */
		draw_gc(pinput,opt);
		break;
	case 5 :         /*comparision graph */
		draw_gc(input, opt);
		break;

		}
		return(1);
	 }           /* end of disp_res() */






	 /*    function to draw grant chart         */

	 draw_gc(int chart [] [3],int opt)
	 {
		int x1,z=100, y, i, j, fillcolor, totbt = 0, col, r = 0, l;

		int left, top, right, bottom;
		float percent[10], res = 0, rr_slice = 0,resl[5],tempf;
		char name[20], name1[20],g[5];
	   /* calculating, total b-time of processes */

	   for(i =0 ; i < nop; i++)
		  totbt = totbt + chart[i][1];

		  /* get process result */
	switch (opt)
	{
	case 1 :           /* fifo */
		strcpy(name,"First In First Out ");
		res = r_fifo;
		break;
	case 2 :           /* sjf */
		strcpy(name,"Shortest Job First  ");
		res = r_sjf;
		break;

       case 3 :           /* priority */
		strcpy(name,"Priority ");
		res = r_pri;
		break;
	case 4 :           /* round robin */
		strcpy(name,"Round Robin ");
		res = r_rr;
		break;

	}

	draw_boarder();
	setcolor(BLUE);
	settextstyle(0,0,2);
	outtextxy(30,50,"C.P.U SCHEDULING");
	line(30,70 ,440,70);
	setcolor(3);
	settextstyle(0,0,1);
	moveto(400 ,50);
	outtext(name);
	setcolor(BLUE);
	settextstyle(2,0,5);
	/*displaying  the given data */
	outtextxy(30,80,"process(s) detail...");
	setcolor(BLUE);
	outtextxy(30,100,"number of process(s) ");
	gotoxy(28,7); printf("%d",nop);
	outtextxy(300,100,"slice time : ");
	gotoxy(57,7); printf("%d",slice);
	setcolor(3);
	moveto(30,120);
	outtext("The avg waiting time taken for the following  process");
	gotoxy(65,8);
	printf("%.2f",res);
	settextstyle(2,0,5);
	setcolor(BROWN);
	outtextxy(75,140,"*process      * bursttime      *priority");
	x1=16;y=11;
	left=70;top=165;right=75;bottom=170;
	for(i=0;i<nop;i++,top=top+16,bottom=bottom+16)
	{
	for(col=0;col<3;col++)
	{
	gotoxy(x1,y);
	printf("%d",input[i][col]);
	x1=x1+18;
	}
	y++;
	x1=16;
	if(input[i][0]==10) /* if process no is 10 */
	fillcolor =12;
	else
	fillcolor=input[i][0];
	setfillstyle(1,fillcolor);
	/* display process indicator */
	bar(left,top,right,bottom);
	}
	if(opt==5)/*comParision graph */
	{
	cleardevice();
	draw_boarder();
	set_title();
	settextstyle(2,0,5);
	outtextxy(250,120,  "  [waiting time]      *ratting*");
	setcolor(RED) ;
	resl[0] =r_fifo;
	resl[1] =r_sjf;
	resl[2] =r_pri;
	resl[3] =r_rr;
	/*sorting result*/
	for(i=0;i<5-1;i++)
	for(j=i+1;j<5;j++)
	if(resl[j]<resl[i])
	{
	/* inter change 2 element */
	tempf=resl[i];
	resl[i]=resl[j];
	resl[j]=tempf;
	}
	settextstyle(0,0,1);
	setcolor(2);
	outtextxy(70,148,"1.First In First Out ");
	setcolor(9);
	outtextxy(70,177,"2.Shortest Job First ");
	setcolor(3);
	outtextxy(70,212,"3.Priority ");
	setcolor(12);
	outtextxy(70,242,"4.Round Robin ");

	settextstyle(0,0,1);
	gotoxy(36,10);
	for(i=0;i<5;i++)
	if(resl[i]==r_fifo)
	break;
	printf("[%2f]",r_fifo);
	setcolor(1);
	outtextxy(420,147,ratting[i]);
	gotoxy(36,12);
	if(r_sjf!=r_fifo)
		for(i=0;i<5;i++)
	if(resl[i]==r_sjf)
	break;
		printf("[%2f]",r_sjf);
	setcolor(2);
	outtextxy(420,177,ratting[i]);
	gotoxy(36,14);
	if(r_pri!=r_sjf)
		for(i=0;i<5;i++)
	if(resl[i]==r_pri)
	break;
		printf("[%2f]",r_pri);
	setcolor(3);
	outtextxy(420,212,ratting[i]);
	gotoxy(36,16);
	if(r_rr!=r_pri)
		for(i=0;i<5;i++)
	if(resl[i]==r_rr)
	break;
		printf("[%2f]",r_rr);
		setcolor(2);
	outtextxy(420,242,ratting[i]);


      setcolor(BROWN);

	outtextxy(400,400,"press any key....");
       getche();
       disp_res();
       return(1);
       }
       /*for fifo /sjf/priority*/
       setcolor(4);
       outtextxy(50, 350, "THE GANTCHART VIEW OF PROCESS(s)      Execution...");
       delay(1000);

       if ((opt == 1)  || (opt == 2) || (opt == 3) )
       {
	 /* calculating % of each process in the scale the gant
chart
	     will display form 50 - 550 pics. the total scale is for
500
	     pics */
	l = 50;
	for (i =0; i < nop; i++)
	{
	percent[i] = ((float) chart[i][1] / totbt) * 500;
	if ( chart[i][0] == 10)    /* if the process no is 10 */
	  fillcolor = 12;

	else
	fillcolor = chart[i][0];
	setfillstyle(1, fillcolor);
	r = l + (int)percent[i];
	delay(1000);
	sound(2000);
	delay(1000);
	nosound();
	     if ((opt == 1)  )
	    {
	    z=*input[i];
			itoa(z,g,10);
	  strncat(g,ka,5);

	outtextxy(r,400,g);

	}
	     if ((opt == 2)  )
	    {
	    z=*sinput[i];
		itoa(z,g,10);
	  strncat(g,ka,5);


	outtextxy(r,400,g);
	}
	     if ((opt == 3)  )
	    {
	    z=*pinput[i];

		itoa(z,g,10);
	  strncat(g,ka,5);

	outtextxy(r,400,g);
	}
	bar(l,375, r,400);
	l = r+2;
	}
	}

	if(opt == 4)    /* grand chart for round-robin */
	{
	l = 50;
	z=0;
	/*       printf("\n%d",pipecount);  */
	for(i = 0; i<pipecount;i++)
	{
	rr_slice = (float)450 / pipecount;
	if (pipe[i] == 10) /* if the process no is 10 */
	{
	fillcolor = 12;

	}
	else
	fillcolor =pipe[i];
	setfillstyle(1, fillcolor);
	r = l + (int)rr_slice;
	delay(1000);
	sound(2000);
	delay(1000);
	nosound();
	z=pipe[i];
		itoa(z,g,10);
	  strncat(g,ka,5);

	outtextxy(r,400,g);

	bar(l, 375, r,400);
	l = r+3;
	}


	}
	getch();
	disp_res();
	return(1);
	}



