#include <mpi.h>
#include <stdio.h>

#define N 10

int main(int argc, char **argv){
    int pid, npr, origen, destino, ndat, tag;
    int temp;

    //Estructura para obtener informacion de un mensaje
    MPI_Status info;

    //Inicializacion del ambiente MPI
    //El numero de procesadores se envia como parametro de ejecucion
    //mpirun -np 4 ./ejecutable
    MPI_Init(&argc, &argv);
    //Obtener rango del procesador
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    //Obtener total de procesadores
    MPI_Comm_size(MPI_COMM_WORLD, &npr);
    //Obtener nombre del procesador
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    //Valida que sea el procesador 0
    if(pid == 0){
        destino = 1;
        tag = 0;
        temp = 3;   //Numero que se enviara
        //Envio de la informacion
        MPI_Send(&temp, 1, MPI_INT, destino, tag, MPI_COMM_WORLD);
        printf("De %d sen envió el numero %d al procesador %d con nombre %s\n", pid, temp, destino, processor_name);
    }
    //Valida que sea el procesador 1
    else if(pid == 1){
        origen = 0;
        tag = 0;
        //Recibe dato de un procesador
        MPI_Recv(&temp, 1, MPI_INT, origen, tag, MPI_COMM_WORLD, &info);
        //Guarda informacion del ambiente MPI
        MPI_Get_count(&info, MPI_INT, &ndat);

        printf("En %d se recibió el numero %d del procesador %d\n", pid, temp, info.MPI_SOURCE);
    }
    else{
        printf("Procesador %d en estado idle\n", pid);
    }
    //Finaliza el ambiente MPI
    MPI_Finalize();
    return 0;
}
