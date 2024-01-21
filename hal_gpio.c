#ifndef HAL_GPIO_C
#define HAL_GPIO_C


#include "hal_gpio.h"
volatile uint8 *tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
volatile uint8 *lat_registers[]={&LATA,&LATB,&LATC,&LATD,&LATE};

Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *pin_config){
   Std_ReturnType ret =E_OK ;
   if(NULL == pin_config){
       ret =E_NOT_OK ;
   }
   
    
   else{
       
        switch( pin_config->pin_direction){
              case GPIO_DIRESTION_INPUT:
                   CLEAR_BIT(*tris_registers[pin_config->port_index],pin_config->pin_index) ;
                   break;
    
               case GPIO_DIRESTION_OUTPUT:
                   SET_BIT(*tris_registers[pin_config->port_index],pin_config->pin_index) ;
                   break;
                   default:ret=E_NOT_OK;
        }
        }
   
   return ret ;
    
}
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config,direction_t*direction_status){
       Std_ReturnType ret =E_OK ;
   if( NULL== pin_config &&NULL= direction_status){
       ret =E_NOT_OK ;
   }
   else{
       
       *direction_status= READ_BIT(*tris_registers[pin_config->port_index],pin_config->pin_index) ;

   }
       
   return ret ;  
}
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config,logic_t logic){
    Std_ReturnType ret =E_OK ;
   if( NULL== pin_config){
        ret =E_NOT_OK ;
   }
   else {
       switch(logic)
         case GPIO_LOW :
            CLEAR_BIT(*lat_registers[pin_config->port_index],pin_config->pin_index) ;
                   break;
    
               case GPIO_HIGH:
                   SET_BIT(*lat_registers[pin_config->port_index],pin_config->pin_index) ;
                   break;
                   default: ret=E_NOT_OK ;   
       }
       
       
       
       
       
   
     return ret ;
    
}
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config,logic_t *logic){
    Std_ReturnType ret =E_OK ;
   if( NULL == pin_config&& NULL =logic){
       ret =E_NOT_OK ;
   }
   else{
       
       *logic=READ_BIT(*port_registers[pin_config->port_index],pin_config->pin_index) ;

           
       }
       
       
       
       
       
   
    
    
  return ret ;   
}
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config){
   Std_ReturnType ret =E_OK ;
   if( NULL== pin_config){
       ret= E_NOT_OK ;
   }
   else {
       
       TOGGLE_BIT (*lat_registers[pin_config->port_index],pin_config->pin_index);
       }
       
       
       
       
       
   
    
    
  return ret ;  
    
    
    
}

Std_ReturnType gpio_pin_intilize(const pin_config_t *pin_config){
    Std_ReturnType ret =E_OK ;
   if( NULL == pin_config){
       ret =E_NOT_OK ;
   }
   else {
       
       ret= gpio_pin_direction_intialize(pin_config)  ;
       ret= gpio_pin_write_logic(pin_config,pin_config->pin_logic );
           
       }
       
       
       
       
       
   
    
    
  return ret ;   
    
    
    
}


Std_ReturnType gpio_port_direction_intialize(port_index_t port,uint8 direction){
   Std_ReturnType ret =E_OK ;
   if(port > 5){
       ret =E_NOT_OK ;
   }
   else{
       
       *tris_registers[port]=direction ;
       }
       
       
       
       
       
   
    
    
  return ret ;  
    
    
    
    
    
}
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction){
   Std_ReturnType ret =E_OK ;
   if( NULL=direction &&port > 5){
       ret =E_NOT_OK ;
   }
   else{
       
       *direction= *tris_registers[port] ;
       }
       
       
       
       
       
   
    
    
  return ret ;   
    
    
    
}
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic){
    Std_ReturnType ret =E_OK ;
   if(port > 5){
       ret =E_NOT_OK ;
   }
   else{
       
        *lat_registers[port]=logic ;
       }
       
       
       
       
       
   
    
    
  return ret ;  
    
    
    
}
Std_ReturnType gpio_port_read_logic(port_index_t port,uint8 *logic){
   Std_ReturnType ret =E_OK ;
   if(port > 5&& NULL=logic){
       ret =E_NOT_OK ;
   }
   else{
       
       *logic =*lat_registers[port] ;
       }
       
       
       
       
       
   
    
    
  return ret ;     
    
    
}
Std_ReturnType gpio_port_toggle_logic(port_index_t port){
     Std_ReturnType ret =E_OK ;
   if(port > 5){
       ret =E_NOT_OK ;
   }
   else{
       
        *lat_registers[port]=*lat_registers[port] ^ 0xff;
       }
       
       
       
       
       
   
    
    
  return ret ;  
    
    
    
    
}

#endif