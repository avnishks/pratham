#include<stdio.h>
#include<stdint.h>

struct position{
  int32_t x;
  int32_t y;
  int32_t z;
};
  
int main()
{
  FILE * f;
  int32_t buffer = 0;
  uint8_t byte,message = 0;
  uint16_t pdop;
  struct position pos;
  
  f = fopen("gps.txt", "rb");
  while(!feof(f))
  {
    byte = fgetc(f);
    buffer = buffer << 8;
    buffer &= 0xFFFFFF00;
    buffer |= (uint32_t) byte;
    
    if(buffer == 0x3F3F04AC)
    {
      fread(&pos,sizeof(struct position), 1, f);
      printf("x = %f m y = %f m z = %f m\n", (float)pos.x/1000, (float)pos.y/1000, (float)pos.z/1000);
      fflush(stdout);
    }
    else if(buffer == 0x3F3F05AC)
    {
      fread(&pos,sizeof(struct position), 1, f);
      printf("v_x = %d mm/s v_y = %d mm/s v_z = %d mm/s\n", pos.x, pos.y, pos.z);
      fflush(stdout);
    }
    else if(buffer == 0x3F3F0BAC)
    {
      fread(&buffer, 2, 1, f);
      fread(&pdop,2, 1, f);
      printf("PDOP = %u\n",pdop);
      fflush(stdout);
    }
    else if(buffer == 0x3F3F0EAC)
    {
      fread(&buffer, 4, 1, f);
      fread(&pos,sizeof(struct position), 1, f);
      printf("LAT = %f deg LONG = %f deg ALT = %f m\n", (float)pos.x/10000000, (float)pos.y/10000000, (float)pos.z/100);
      fflush(stdout);
      message = 1;
    }
    
    if(message)
    {
      printf("\n");
      message = 0;
    }
  }
    
  fclose(f);
  return 0;
}
