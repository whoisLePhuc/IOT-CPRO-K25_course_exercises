#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define SENSOR_NAME_LENGHT 20
#define MAX_SENSORS 10

// Define a structure for sensor nodes
typedef struct{
    int id;
    char name[SENSOR_NAME_LENGHT];
    float sensor_value;
}SensorNode;

// Define a structure for the sensor manager
typedef struct{
    int Sensor_Count;
    SensorNode *sensors[MAX_SENSORS];
    void( *Add_Sensor)(int id, const char* name);
    void( *Remove_Sensor)(int id);
    void( *Upload_Sensor_Data)();
    void( *Get_Sensor_Data)();
}SensorManager;

static SensorManager *Sensor_Manager_Instance = NULL;

void Add_Sensor(int id, const char* name){
    if(Sensor_Manager_Instance->Sensor_Count < MAX_SENSORS){
        SensorNode *New_Sensor = (SensorNode *)malloc(sizeof(SensorNode));
        if(New_Sensor != NULL){
            New_Sensor->id = id;
            snprintf(New_Sensor->name, SENSOR_NAME_LENGHT, "%s", name);
            New_Sensor->sensor_value = 0.0f;
            Sensor_Manager_Instance->sensors[Sensor_Manager_Instance->Sensor_Count++] = New_Sensor;
            printf("Sensor added: ID = %d, Name = %s\n", New_Sensor->id, New_Sensor->name);
        }else{
            printf("Failed to allocate memory for new sensor\n");
            return;
        }
    }else{
        printf("Maximum sensor limit reached\n");
        return;
    }
}   

void Remove_Sensor(int id){
    int found = 0;
    for(int i = 0; i < Sensor_Manager_Instance->Sensor_Count; i++){
        if(Sensor_Manager_Instance->sensors[i] != NULL && Sensor_Manager_Instance->sensors[i]->id == id){
            found = 1;
            free(Sensor_Manager_Instance->sensors[i]);
            for(int j = i; j < Sensor_Manager_Instance->Sensor_Count - 1; j++){
                Sensor_Manager_Instance->sensors[j] = Sensor_Manager_Instance->sensors[j + 1];
            }
            Sensor_Manager_Instance->sensors[Sensor_Manager_Instance->Sensor_Count - 1] = NULL;
            Sensor_Manager_Instance->Sensor_Count--;
            printf("Sensor removed: ID = %d\n", id);
            break;
        }
    }
    if(!found){
        printf("Sensor with ID = %d not found\n", id);
    }
}

void Upload_Sensor_Data(){
    for(int i = 0; i < Sensor_Manager_Instance->Sensor_Count; i++){
        if(Sensor_Manager_Instance->sensors[i] != NULL){
            // Simulate uploading sensor data
            printf("Uploading data for Sensor ID: %d, Name: %s, Value: %.2f\n", 
                   Sensor_Manager_Instance->sensors[i]->id, 
                   Sensor_Manager_Instance->sensors[i]->name, 
                   Sensor_Manager_Instance->sensors[i]->sensor_value);
        }
    }
}

void Get_Sensor_Data(){
    for(int i=0; i < Sensor_Manager_Instance->Sensor_Count; i++){
        if(Sensor_Manager_Instance->sensors[i] != NULL){
            Sensor_Manager_Instance->sensors[i]->sensor_value = (float)(rand() % 100); // Simulate sensor data
            printf("Get Sensor ID: %d, Name: %s, Value: %.2f\n", 
                   Sensor_Manager_Instance->sensors[i]->id, 
                   Sensor_Manager_Instance->sensors[i]->name, 
                   Sensor_Manager_Instance->sensors[i]->sensor_value);
        }
    }

}

SensorManager *Init_Sensor_Manager(){
    if(Sensor_Manager_Instance == NULL){
        Sensor_Manager_Instance = (SensorManager *)malloc(sizeof(SensorManager));
        if(Sensor_Manager_Instance != NULL){
            Sensor_Manager_Instance->Sensor_Count = 0;
            memset(Sensor_Manager_Instance->sensors, 0, sizeof(Sensor_Manager_Instance->sensors));
            Sensor_Manager_Instance->Add_Sensor = Add_Sensor;
            Sensor_Manager_Instance->Remove_Sensor = Remove_Sensor;
            Sensor_Manager_Instance->Upload_Sensor_Data = Upload_Sensor_Data;
            Sensor_Manager_Instance->Get_Sensor_Data = Get_Sensor_Data;
        }else{
            printf("Failed to allocate memory for sensor manager\n");
        }
    }
    return Sensor_Manager_Instance;
}

int main(){
    SensorManager *Sensor_manager = Init_Sensor_Manager();
    Sensor_manager->Add_Sensor(1, "Temperature Sensor");
    Sensor_manager->Add_Sensor(2, "Humidity Sensor");
    Sensor_manager->Add_Sensor(3, "Pressure Sensor");
    Sensor_manager->Remove_Sensor(2);
    Sensor_manager->Add_Sensor(2, "Humidity Sensor");
    Sensor_manager->Get_Sensor_Data();
    Sensor_manager->Upload_Sensor_Data();
}