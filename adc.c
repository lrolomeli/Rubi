
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

/*********************************** CONFIGURACION INICIAL DE LAS ENTRADAS ANALOGICAS **************************/
    ADCON1.PCFG = 0x0D;

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

    // Esperamos a que el valor del potenciometro se vea reflejado en el registro ADRES
    while(ADCON0bits.GO_DONE == 1);
    
    // Y se realiza la lectura del potenciometro en cuestion.
    return ADRES;

}