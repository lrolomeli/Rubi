
void moverDerechaM1();
void moverDerechaM2();
void moverIzquierdaM1();
void moverIzquierdaM2();
unsigned int leerPotenciometro(unsigned char canalPotenciometro);

unsigned char A=0;
unsigned char B=1;
unsigned char C=2;
unsigned char D=3;

unsigned int posicion_m1=0;
unsigned int posicion_m2=0;
unsigned char paso_final_m1 = 0;
unsigned char paso_final_m2 = 0;

unsigned int potenciometro_0 = 0;
unsigned int potenciometro_1 = 0;

void main(void) {
    /** Configurando referencia de voltaje por default la misma del pic 5v */
    ADCON1bits.VCFG = 0x00;
    /** Configurando los pines digitales o analogicos */
    ADCON1bits.PCFG = 0x0D;
    /** Seleccion del canal analogico 0 */
    ADCON0bits.CHS = 0x00;
    /** Configurando el tiempo de adquisicion para la entrada analogica */
    ADCON2bits.ACQT = 0x02;
    /** Configurando la conversion del reloj */
    ADCON2bits.ADCS = 0x01;
    /** Configurando el orden de acomodo de los bits en la lectura del ADC */
    ADCON2bits.ADFM = 0x01;
    
    /** Configura la entrada analogica del potenciometro */
    TRISAbits.RA0 = 1;
    TRISAbits.RA1 = 1;
    
    /** Configuracion de las salidas digitales hacia el motor */
    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 0;
    TRISBbits.RB2 = 0;
    TRISBbits.RB3 = 0;
    TRISBbits.RB4 = 0;
    TRISBbits.RB5 = 0;
    TRISBbits.RB6 = 0;
    TRISBbits.RB7 = 0;
    
    /** Estado inicial de las salidas/bobinas del motor apagadas. */
    LATBbits.LB0 = 0;
    LATBbits.LB1 = 0;
    LATBbits.LB2 = 0;
    LATBbits.LB3 = 0;
    LATBbits.LB4 = 0;
    LATBbits.LB5 = 0;
    LATBbits.LB6 = 0;
    LATBbits.LB7 = 0;   

    
    for(;;)
    {
        potenciometro_0 = leerPotenciometro(0);
        potenciometro_1 = leerPotenciometro(1);

        if(potenciometro_0 > posicion_m1)
        {
            //girar a la derecha
            moverDerechaM1();
        }
        else if(potenciometro_0 < posicion_m1){
            // girar a la izquierda
            moverIzquierdaM1();
        }
        else{
            //nada
        }

        if(potenciometro_1 > posicion_m2)
        {
            //girar a la derecha
            moverDerechaM2();
        }
        else if(potenciometro_1 < posicion_m2){
            // girar a la izquierda
            moverIzquierdaM2();
        }
        else{
            //nada
        }

  
    }
    
}

void moverIzquierdaM1() {
      // put your main code here, to run repeatedly:

      if(paso_final_m1 == A){
        LATBbits.LB0=0;
        LATBbits.LB1=0;
        LATBbits.LB2=0;
        LATBbits.LB3=1;
        paso_final_m1 = D;
        posicion_m1--;
         __delay_ms(10);
      }
    
     else if(paso_final_m1 == D){
        LATBbits.LB0=0;
        LATBbits.LB1=0;
        LATBbits.LB2=1;
        LATBbits.LB3=0;
        paso_final_m1 = C;
        posicion_m1--;
          __delay_ms(10);
      }
  
      else if( paso_final_m1 == C){
        LATBbits.LB0=0;
        LATBbits.LB1=1;
        LATBbits.LB2=0;
        LATBbits.LB3=0;
        paso_final_m1 = B;
        posicion_m1--;
        __delay_ms(10);
      }

      else if(paso_final_m1 == B){
        LATBbits.LB0=1;
        LATBbits.LB1=0;
        LATBbits.LB2=0;
        LATBbits.LB3=0;
        paso_final_m1 = A;
         posicion_m1--;
        __delay_ms(10);
      }

}

void moverIzquierdaM2() {
      // put your main code here, to run repeatedly:

      if(paso_final_m2 == A){
        LATBbits.LB4=0;
        LATBbits.LB5=0;
        LATBbits.LB6=0;
        LATBbits.LB7=1;
        paso_final_m2 = D;
        posicion_m2--;
         __delay_ms(10);
      }
    
     else if(paso_final_m2 == D){
        LATBbits.LB4=0;
        LATBbits.LB5=0;
        LATBbits.LB6=1;
        LATBbits.LB7=0;
        paso_final_m2 = C;
        posicion_m2--;
          __delay_ms(10);
      }
  
      else if( paso_final_m2 == C){
        LATBbits.LB4=0;
        LATBbits.LB5=1;
        LATBbits.LB6=0;
        LATBbits.LB7=0;
        paso_final_m2 = B;
        posicion_m2--;
        __delay_ms(10);
      }

      else if(paso_final_m2 == B){
        LATBbits.LB4=1;
        LATBbits.LB5=0;
        LATBbits.LB6=0;
        LATBbits.LB7=0;
        paso_final_m2 = A;
         posicion_m2--;
        __delay_ms(10);
      }

}


void moverDerechaM1(){
      
      
      if(paso_final_m1 == D){
        LATBbits.LB0=1;
        LATBbits.LB1=0;
        LATBbits.LB2=0;
        LATBbits.LB3=0;
        paso_final_m1 = A;
        posicion_m1++;
        __delay_ms(10);
      }

      
    
      else if(paso_final_m1 == A){
        LATBbits.LB0=0;
        LATBbits.LB1=1;
        LATBbits.LB2=0;
        LATBbits.LB3=0;
        paso_final_m1 = B;
         posicion_m1++;
        __delay_ms(10);
      }
  
      else if(paso_final_m1 == B){
        LATBbits.LB0=0;
        LATBbits.LB1=0;
        LATBbits.LB2=1;
        LATBbits.LB3=0;
        paso_final_m1 = C;
         posicion_m1++;
        __delay_ms(10);
      }

      else if(paso_final_m1 == C){
         LATBbits.LB0=0;
        LATBbits.LB1=0;
        LATBbits.LB2=0;
        LATBbits.LB3=1;
        paso_final_m1 = D;
        posicion_m1++;
       __delay_ms(10);
      }

   
}

void moverDerechaM2(){
      
      
      if(paso_final_m2 == D){
        LATBbits.LB4=1;
        LATBbits.LB5=0;
        LATBbits.LB6=0;
        LATBbits.LB7=0;
        paso_final_m2 = A;
         posicion_m2++;
        __delay_ms(10);
      }

      
    
      else if(paso_final_m2 == A){
        LATBbits.LB4=0;
        LATBbits.LB5=1;
        LATBbits.LB6=0;
        LATBbits.LB7=0;
        paso_final_m2 = B;
         posicion_m2++;
        __delay_ms(10);
      }
  
      else if(paso_final_m2 == B){
        LATBbits.LB4=0;
        LATBbits.LB5=0;
        LATBbits.LB6=1;
        LATBbits.LB7=0;
        paso_final_m2 = C;
         posicion_m2++;
        __delay_ms(10);
      }

      else if(paso_final_m2 == C){
         LATBbits.LB4=0;
        LATBbits.LB5=0;
        LATBbits.LB6=0;
        LATBbits.LB7=1;
        paso_final_m2 = D;
        posicion_m2++;
       __delay_ms(10);
      }

   
}

/**
 * El registro ADCON0 debe configurarse cada vez que se requiera leer un canal
 * analogico. (Al inicio debe estar en 0x00 para inciar con el conversor de ADC apagado y ahorrar energia)
 * Y solo encender el conversor es decir ADCON0.ADON cuando sea necesaria la lectura del canal.
 * 
 * Canal es sinonimo de Entrada Analogica. Es decir por cada potenciometro debe habilitarse y leerse un canal distinto.
 * 
 * El otro registro que se Debe modificar para aumentar a la lectura de mas entradas analogicas es el registro
 * ADCON1.PCFG con este registro seleccionas cuales pines de que puertos seran configurados como analogicos y cuales digitales.
 * 
 **/

unsigned int leerPotenciometro(unsigned char canalPotenciometro) {

    /**
     * Deshabilita cualquier otro canal del ADC 
     * porque unicamente se puede leer un potenciometro a la vez.
     **/
    ADCON0 = 0x00;

    /**
     * Habilita solo el canal que queremos leer ya sea el primer
     * o el segundo potenciometro o cualquier otra entrada analogica.
     **/
    ADCON0bits.CHS = canalPotenciometro;

    // Se enciende el conversor analogico digital para el canal ya especificado
    ADCON0bits.ADON = 1;

    ADCON0bits.GODONE = 1;
    // Esperamos a que el valor del potenciometro se vea reflejado en el registro ADRES
    while(ADCON0bits.GO_DONE == 1);
    
    // Y se realiza la lectura del potenciometro en cuestion.
    return ADRES;

}