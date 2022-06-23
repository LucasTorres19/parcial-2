/** \brief Parsea los datos los datos obtenidos del archivo.
 * \param path char*
 * \param pArrayServicio LinkedList*
 * \return int
 *
 */
int parser_ServicioFromText(FILE* pFile , LinkedList* pArrayServicio);

/** \brief Crea o guardar en un archivo un array.
 * \param path char*
 * \param pArrayServicio LinkedList*
 * \return int
 *
 */
int GuardarEnArchivo(char* path,LinkedList* pArrayServicio);
