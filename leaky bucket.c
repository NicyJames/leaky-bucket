#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define NOF_PACKETS 10
int randm(int a)
{
int rn=(random() % 10) % a;
return rn==0 ? 1 : rn;
}
int main()
{
int packet_sz[NOF_PACKETS],i,clk,b_size,o_rate,p_sz_rm=0,p_sz,p_time,op;
for(i=0;i<NOF_PACKETS;++i)
packet_sz[i]=randm(6) * 10;
for(i=0;i<NOF_PACKETS;++i)
printf("\npacket[%d]:%d bytes\t",i,packet_sz[i]);
printf("\nenter the output rate:");
scanf("%d",&o_rate);
printf("enter the bucket size:");
scanf("%d",&b_size);
for(i=0;i<NOF_PACKETS;++i)
{
if((packet_sz[i] + p_sz_rm)> b_size)
{
if(packet_sz[i]>b_size)
printf("\n\nincoming packet size(%dbytes) is greater than bucket capacity (%dbytes)-PACKET REJECTED",packet_sz[i],b_size);
else
printf("\n\nbucket capacity exceeded-PACKETS REJECTED !!");
}
else
{
p_sz_rm += packet_sz[i];
printf("\n\nincoming packet size : %d",packet_sz[i]);
printf("\nbytes remaining to transmit: %d",p_sz_rm );
p_time=randm(4) * 10;
printf("\ntime left for transmission: %d units",p_time);
for(clk = 10; clk <= p_time; clk +=10)
{
sleep(1);
if(p_sz_rm)
{
if(p_sz_rm <= o_rate)
{
op=p_sz_rm;
p_sz_rm=0;
}
else
{
op = o_rate;
p_sz_rm -= o_rate;
}
printf("\n packet of size %d transmitted",op);
printf("----bytes remaining to transmit: %d",p_sz_rm);
}
else
{
printf("time left for transmission: %d units",p_time-clk);
printf("\n no packets to transmit");
}
}
}
}
}
