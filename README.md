# mksCarCheckList
Mobile Appp that helps the user reminding car maintenance tasks, (change oil, check water level, etc).

0. Cargo datos de cada vehículo
  *  Nombre
  *  Patente
  *  Marca
  *  Modelo
  *  Año
  *  Foto ?
  *  Consumido:
    *    Cargo km realizado
    *    Cargo km del último cambio de aceite
    *    Cargo km de cubiertas, 
    *    Cargo km de última rotación.
    *    Cargo km del último cambio de aceite.
1. Cada n dias el programa se activa y pregunta por los kms cargados.
  *  Los primeros días de uso entreno el programa cargando kms realizados ese día
  *  A medida que pasa el tiempo voy cargando km hechos. El programa estima de alguna manera los km actuales.
2. Cuando se esta por cumpllir un plazo (ej, limite de km en cambio de aceite aparecen recordatorios).
3. El programa muestra un listado en orden cronologico de los km recorridos, los cambios, etc
4. Puede tener un link al telefono del mecanico, seguro, etc
