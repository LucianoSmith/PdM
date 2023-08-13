###TRABAJO FINAL

###VÁLVULA AUTONOMA PARA SISTEMAS DE CORREO NEUMÁTICO

###(PROGRAMACIÓN DE MICROCONTROLADORES)

Se trata de una válvula guillotina autónoma para la utilización dentro de sistemas de correo neumático.
La válvula funciona con dos sensores ópticos que detectan la llegada y salida de los contenedores. Al detectar un contenedor en la entrada, la válvula espera un tiempo t1 predeterminado (por ejemplo: 4 segundos) y luego, verifica nuevamente la presencia del contenedor y, si el mismo es detectado, abre la guillotina utilizando un mecanismo accionado por un motor eléctrico. Las posiciones de la guillotina se detectan por medio de los sensores magnéticos. Luego, se debe detectar el paso del contenedor por el sensor óptico de salida, que al igual que en el sensor de entrada debe esperar un tiempo preconfigurado t2 para volver a sensar y verificar que el contenedor no se encuentra en el paso de la guillotina. De ser así cierra la guillotina.

La válvula maneja dos leds indicadores, un led verde que indica encendido y un led rojo que indica funcionamiento u error dependiendo si queda fijo o parpadeando.

Por medio de una interfaz UART se podrá monitorear acciones realizadas por la válvula.


HARDWARE: NUCLEO 429ZI
