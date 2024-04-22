#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<unistd.h>
#define WINDOW_SIZE 4
#define MAX_PACKETS 15
#define TIMEOUT 3
typedef struct {
    int seq_num;
    bool acked;
}Packet;
void send_packet(Packet *window,int seq_num)
{
    printf("Sending packet with sequence number %d\n",seq_num);
    sleep(1);
    window[seq_num].acked=true;
}
void receive_ack(Packet *window,int ack_num)
{
    printf("received acknowledgment for packet with sequence number %d\n",ack_num);
    window[ack_num].acked=false;
}
int main()
{
    Packet window[WINDOW_SIZE];
    int base=0;
    int next_seq_num=0;
    int packets_sent=0;
    for(int i=0;i<WINDOW_SIZE;i++)
    {
        window[i].seq_num=i;
        window[i].acked=false;
    }
    while(packets_sent<MAX_PACKETS)
    {
        for(int i=base;i<base+WINDOW_SIZE;i++)
        {
            if(i<MAX_PACKETS && !window[i%WINDOW_SIZE].acked)
            {
                send_packet(window,i%WINDOW_SIZE);
                packets_sent++;
        }
    }
    for(int i=base;i<base+WINDOW_SIZE;i++)
        {
            if(i<MAX_PACKETS && window[i%WINDOW_SIZE].acked)
            {
                receive_ack(window,i%WINDOW_SIZE);
                base++;
        }
    }
}
return 0;
}
