/*In an operating system that uses paging for memory management, a page
   replacement algorithm is needed to decide which page needs to be replaced
   when new page comes in.

   Page Fault – A page fault happens when a running program accesses a memory
   page that is mapped into the virtual address space, but not loaded in
   physical memory.

   Since actual physical memory is much smaller than virtual memory, page faults
   happen. In case of page fault, Operating System might have to replace one of
   the existing pages with the newly needed page.
   In this algorithm page will be replaced which is least recently used.*/
#include <stdio.h>

int main() // page is already in frame .HIT occured
{
  a = 1;
  b = 1;
  break;
}
}
if (a == 0) // to fill empty spaces
{
  for (m = 0; m < total_frames; m++) {
    if (frames[m] == -1) {
      frames[m] = pages[n]; // add page to empty frame .
      b = 1;
      break;
    }
  }
}
if (b ==
    0) // if there is no empty frames then add page to top of the frame array
{
  for (m = 0; m < total_frames; m++) {
    temp[m] = 0;
  }
  for (k = n - 1, l = 1; l <= total_frames - 1;
       l++, k--) // pages in frames are compared with pages in references.
  {
    for (m = 0; m < total_frames; m++) {
      if (frames[m] == pages[k]) {
        temp[m] = 1; // if the page is recently used then temp=1
      }
    }
  }
  for (m = 0; m < total_frames; m++) {
    if (temp[m] == 0)
      position = m; // this is the least recently used framenumber.
  }
  frames[position] = pages[n];
  page_fault++;
}
printf("\n");
for (m = 0; m < total_frames; m++) {
  printf("%d\t", frames[m]); // display the frames.
}
}
printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
return 0;
}
