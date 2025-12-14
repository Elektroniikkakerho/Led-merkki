#include <avr/io.h>
#include <util/delay.h>

#include "vilkutus.h"

#include "lediportit.h"             // Mikäli juotit ledit väärin päin,
// #include "lediportit_vaarin.h"   // Vaihda tästä otsikko tiedosto.


///     K0 0
#define K1 0.001
#define K2 0.2
#define K3 1
#define K4 2
#define K5 4
#define K6 8
#define K7 14
#define K8 27
#define K9 50
#define K10 80
#define K11 110
#define K12 160
#define K13 200
#define K14 250
#define K15 312

///pimeä vaihe
#define P0 312
#define P1 312-K1
#define P2 312-K2
#define P3 312-K3
#define P4 312-K4
#define P5 312-K5
#define P6 312-K6
#define P7 312-K7
#define P8 312-K8
#define P9 312-K9
#define P10 312-K10
#define P11 312-K11
#define P12 312-K12
#define P13 312-K13
#define P14 312-K14
#define P15 0



int8_t kirkkaus[32] = {0};
//uint8_t kirkkaus[32] = {0x1,0x1,0x1,0x1,0x1,   0x1,0x1,0x1,0x1,0x1,   0x1,0x1,0x1,0x1,0x1,  0x1,0x1,0x1,0x1,0x1,  0x1,0x1,0x1,0x1,0x1,   0x1,0x1,0x1,0x1,0x1, 0x1,0x1};

/*
void tauko(uint16_t ctr)
   {
   while (ctr != 0)  
      {
      asm volatile("nop"); 
      ctr--;
      }

   }

void tauko2(uint16_t ctr)
   {
   while (ctr != 0)
      {
      _delay_ms(1);
      ctr--;
      }
   }
*/
void vilkutus(void)
{
   uint8_t led = 0;
   uint8_t *kirkptr;
   uint8_t *paptr;
   uint8_t *pbptr;
   kirkptr = &kirkkaus[0]; //kirkkaustaulukon pointteri
   paptr = &pa[0]; //PortA taulukon pointteri
   pbptr = &pb[0];
   while (led < 32)
   {
      switch (*kirkptr)
         {
         case 0:
            break;
         case 1:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K1);
            PORTA = alloff_pa;
            PORTB = alloff_pb;

            break;
         case 2:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K2);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 3:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K3);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 4:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K4);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 5:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K5);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 6:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K6);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 7:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K7);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 8:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K8);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 9:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K9);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 10:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K10);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 11:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K11);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 12:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K12);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 13:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K13);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 14:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K14);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         case 15:
            PORTA = *paptr;
            PORTB = *pbptr;
            _delay_us(K15);
            PORTA = alloff_pa;
            PORTB = alloff_pb;
            break;
         default: // negatiiviset ajatellaan nolliksi
            break;
         }

      kirkptr++;
      paptr++;
      pbptr++;
      led++;
   }

   ///sammuttelu ja venailu

   PORTA = alloff_pa;
   PORTB = alloff_pb;
   //PORTA = pa[16];
   //PORTB = pb[16];
   led = 0;
   kirkptr = &kirkkaus[0]; //kirkkaustaulukon pointteri
   while (led < 32)
      {
      switch (*kirkptr)
         {
         case 0:
            _delay_us(P0);
            break;
         case 1:
            _delay_us(P1);
            break;
         case 2:
            _delay_us(P2);
            break;
         case 3:
            _delay_us(P3);
            break;
         case 4:
            _delay_us(P4);
            break;
         case 5:
            _delay_us(P5);
            break;
         case 6:
            _delay_us(P6);
            break;
         case 7:
            _delay_us(P7);
            break;
         case 8:
            _delay_us(P8);
            break;
         case 9:
            _delay_us(P9);
            break;
         case 10:
            _delay_us(P10);
            break;
         case 11:
            _delay_us(P11);
            break;
         case 12:
            _delay_us(P12);
            break;
         case 13:
            _delay_us(P13);
            break;
         case 14:
            _delay_us(P14);
            break;
         case 15:
            _delay_us(P15);
            break;
         default:
            _delay_us(P15);
            break;
         }
      kirkptr++;
      led++;
      }
   }

