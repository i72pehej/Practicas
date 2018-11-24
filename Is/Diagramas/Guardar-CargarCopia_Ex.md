**Guardar Copia de Seguridad**

Se realiza un guardado de seguiridad de la base de datos por medio de una solicitud por parte del usuario o de forma periódica por el sistema.

Tras realizar la petición, el sistema comprobaría la existencia de una base de datos con información, mandando un mensaje de error en caso de no encontrarla, y realizando dicha copia de seguridad sobreescribiendo cualquier otra posible copia anterior. Al finalizar mostraría un mensaje de confirmación de la operación al usuario.

**Cargar Copia de Seguridad**

Se realiza una carga de la copia de seguiridad de la base de datos por medio de una solicitud por parte del usuario al iniciar el sistema.

Tras realizar la petición, el sistema comprobaría la existencia de una copia de seguridad con información, mandando un mensaje de error en caso de no encontrarla, y realizando la carga de dicha copia de seguridad sobreescribiendo cualquier posible base de datos presente. Al finalizar mostraría un mensaje de confirmación de la operación al usuario.
