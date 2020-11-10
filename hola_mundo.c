#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv){
    //Inicializacion del ambiente MPI
    MPI_Init(NULL, NULL);

    //Obtener el numero de procesadores
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    //Obtener el rango del procesador
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    //Obtener nombre del procesador
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    //Imprimir mensaje Hola Mundo
    printf("Hola mundo del procesador %s, rank %d de los %d procesadores\n", processor_name, world_rank, world_size);

    //Finalizar el ambiente MPI
    MPI_Finalize();
}
