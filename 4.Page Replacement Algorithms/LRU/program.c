/*In an operating system that uses paging for memory management, a page replacement algorithm is needed to decide which page needs to be replaced when new page comes in.

   Page Fault – A page fault happens when a running program accesses a memory page that is mapped into the virtual address space, but not loaded in physical memory.

   Since actual physical memory is much smaller than virtual memory, page faults happen. In case of page fault, Operating System might have to replace one of the existing pages with the newly needed page.
   In this algorithm page will be replaced which is least recently used.*/
#include <stdio.h>

int main()
{
        int frames[10], temp[10], pages[10];
        int total_pages, m, n, position, k, l, total_frames;
        int a = 0, b = 0, page_fault = 0;
        printf("\nEnter Total Number of Frames:\t");
        scanf("%d", &total_frames);
        for(m = 0; m < total_frames; m++)
        {
                frames[m] = -1; //initialize frame with -1.
        }
        printf("Enter Total Number of Pages:\t");
        scanf("%d", &total_pages);
        printf("Enter Values for Reference String:\n");
        for(m = 0; m < total_pages; m++)
        {
                printf("Value No.[%d]:\t", m + 1);
                scanf("%d", &pages[m]);
        }
        for(n = 0; n < total_pages; n++)
        {
                a = 0, b = 0;
                for(m = 0; m < total_frames; m++)
                {
                        if(frames[m] == pages[n]) //page is already in frame .HIT occured
                        {
                                a = 1;
                                b = 1;
                                break;
                        }
                }
                if(a == 0) //to fill empty spaces
                {
                        for(m = 0; m < total_frames; m++)
                        {
                                if(frames[m] == -1)
                                {
                                        frames[m] = pages[n]; //add page to empty frame .
                                        b = 1;
                                        break;
                                }
                        }
                }
                if(b == 0) //if there is no empty frames then add page to top of the frame array
                {
                        for(m = 0; m < total_frames; m++)
                        {
                                temp[m] = 0;
                        }
                        for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--) // pages in frames are compared with pages in references.
                        {
                                for(m = 0; m < total_frames; m++)
                                {
                                        if(frames[m] == pages[k])
                                        {
                                                temp[m] = 1; //if the page is recently used then temp=1
                                        }
                                }
                        }
                        for(m = 0; m < total_frames; m++)
                        {
                                if(temp[m] == 0)
                                        position = m;  //this is the least recently used framenumber.
                        }
                        frames[position] = pages[n];
                        page_fault++;
                }
                printf("\n");
                for(m = 0; m < total_frames; m++)
                {
                        printf("%d\t", frames[m]); //display the frames.
                }
        }
        printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
        return 0;
}
