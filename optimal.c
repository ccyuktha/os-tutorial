#include<stdio.h>
int main()
{
    int FrameNo, PageNo, frames[10], pages[30], Positions[10],pos, max, faults = 0;
    int hits=0,f1, f2, f3, i, j, k;
    int hit[30];
    printf("No of Frames: ");
    scanf("%d", &FrameNo);
    
    printf("No of Pages in Reference String: ");
    scanf("%d", &PageNo);
    
    printf("Enter The pages in the Reference String: ");
    
    for(i = 0; i < PageNo; ++i){
        scanf("%d", &pages[i]);
    }
    
    //Defaultly all the data in the frames are -1 as to show they are empty
    printf("\n\n\n\n");
    for(i = 0; i < FrameNo; ++i){
        frames[i] = -1;
    }
    
    //Display things 
    
    printf("String |\t");
    for(i=0;i<FrameNo;i++)
    {
        printf("f%d\t",i);
    }
    printf("| Hit or Miss\n");
    printf("---------------------------------------------------------------\n");
    
    //start to check the frames
    for(i = 0; i < PageNo; ++i){
        f1 = f2 = 0;
        for(j = 0; j < FrameNo; ++j){                   // it checks of its a hit or not  
            if(frames[j] == pages[i]){
                   f1 = f2 = 1;
                   hit[i] = 1;
                   hits+=1;
                   break;
               }
        }
        
        if(f1 == 0){
            for(j = 0; j < FrameNo; ++j){
                if(frames[j] == -1){
                    faults++;                           // intial miss when all the frames are not filled 
                    hit[i]=0;
                    frames[j] = pages[i];
                    f2 = 1;
                    break;
                }
            }    
        }
        
        if(f2 == 0){
         f3 =0;
        
            for(j = 0; j < FrameNo; ++j){
             Positions[j] = -1;
            
             for(k = i + 1; k < PageNo; ++k){           //takes the postions of all the pages that are repeating 
             if(frames[j] == pages[k]){
             Positions[j] = k;
             break;
             }
             }
            }
            
            for(j = 0; j < FrameNo; ++j){
             if(Positions[j] == -1){
             pos = j;                                   
             f3 = 1;                                    //and other if not repeating puts -1
             break;
             }
            }
            
            if(f3 ==0){
             max = Positions[0];
             pos = 0;
            
             for(j = 1; j < FrameNo; ++j){                      // if all are repeating
             if(Positions[j] > max){                            // checks which is repeating after the most time
             max = Positions[j];
             pos = j;
             }
             }            
            }
    hit[i]=0;                                                   // replaces the frame which repeats after the most time
    frames[pos] = pages[i];
    faults++;
        }
        
        printf("%d      |\t",pages[i]);
        for(j = 0; j < FrameNo; ++j){
            if(frames[j] == -1)
            {
                printf("empty\t");                              //printf if the frame is empty 
            }
            else{
            printf("%d\t", frames[j]);
            }
            
        }
        if(hit[i] == 0){
            printf("| Miss");                                   // prints if the replacement is 
        }
        else if (hit[i]==1)
        {
            printf("| Hit");
        }
        printf("\n");
    }
    
    printf("\n\nPage faults/Misses = %d", faults);
    printf("\tHits = %d",hits);
    return 0;
}
