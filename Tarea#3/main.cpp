#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

void CreaArchivo(string NameArch){
 ofstream out(NameArch.c_str());//Se abre un stream y se le asigna  el nombre para crear el archivo
 if(out.is_open())//Si el archivo fue creado
 cout << "Archivo creado con exito..." << endl;// Imprime esto
 out.close();// archivo
}

// Esta funcion de Listar archivos la sacamos de la clase programacion 3
void ListarDirectorio(char directorio[100]){
   WIN32_FIND_DATA ffd;
   LARGE_INTEGER filesize;
   TCHAR szDir[MAX_PATH];
   size_t length_of_arg;
   HANDLE hFind = INVALID_HANDLE_VALUE;
   DWORD dwError=0;
    r
    string tipo_archivo;
   string nombre_archivo;

   // Agregamos /* a la cadena del directorio
   strcat(directorio,"\\*");

   hFind = FindFirstFile(directorio, &ffd);

   if (INVALID_HANDLE_VALUE == hFind)
   {
      cout << "Error en FindFirstFile" << endl;
   }

   // Listamos los directorios y archivos en el directorio
   do
   {
	  // Pasamos el nombre del archivo a la variable tipo string
      nombre_archivo = ffd.cFileName;

      if ((nombre_archivo != ".") && (nombre_archivo != "..")){
    	  if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
          {
			  // Es un directorio
		      tipo_archivo = "Dire";
          }
          else
          {
			  // Es un archivo
			  tipo_archivo = "Arch";
          }
          cout << "<" << tipo_archivo << ">   " << setw(50) << left << nombre_archivo <<endl;
	  }
   }
   while (FindNextFile(hFind, &ffd) != 0);

   dwError = GetLastError();

   if (dwError != ERROR_NO_MORE_FILES)
   {
      cout << endl << "Error desconocido";
   }

   FindClose(hFind);

}

void EditarArchivo(string NameArch){
	string linea;
	ofstream out(NameArch.c_str(),ios::in);
	 if(!out.is_open()){
        out.open(NameArch.c_str());
        }

	cout << "> ";
	cin.ignore();
    getline(cin,linea);

	while (linea != ""){
		out << linea << endl;
    	cout << "> ";
    	getline(cin,linea);
	}
    out.close();
    cout << endl << "Se termino de editar el archivo" << endl;
}

void Mostrar(string NameArch){

	char path_archivo[200] = "C:\\Tarea#3\\";
	string linea;
	strcpy(path_archivo, NameArch.c_str());

	ifstream archivolectura(NameArch.c_str());

	cout << endl << "Contenido del archivo: " << NameArch << endl;

	if (!archivolectura){
		cout << endl << "No se pudo abrir el archivo";
	}
	else{
		while (getline(archivolectura, linea)){
			cout << linea << endl;
		}
	}
cout<<endl;

}
void Help(){
cout<<"Con el comando 'creararchivo' se crea un archivo nuevo"<<endl;
cout<<"Con el comando 'listararchivos' se listan todos los archivos de una carpeta en especifico"<<endl;
cout<<"Con el comando 'modificararchivo' se modifica el texto de un archivo"<<endl;
cout<<"Con el comando 'verarchivo'  Se muestra el contenido del archivo"<<endl;
cout<<"Con el comando 'Salir' se sale del programa"<<endl;

}

 int str2int (const string &str) {
  stringstream ss(str);
  int num;
  if((ss >> num).fail())
  {
      //ERROR
  }
  return num;
}
int main()
{
   /* int uno = str2int("creararchivo");
    int dos = str2int("listararchivos");
    int tres = str2int("modificararchivos");
    int cuatro =str2int("verarchivo");
    string opcion = " ";
    cin>>opcion;
    switch(str2int(opcion)){
    case uno :{
    string Archivo;
   cout << "Abriendo Archivo" << endl;
   cin>>Archivo;
   CreaArchivo(Archivo);}
    break;
    case dos:{
   char directorio[100];

   cout << "Ingrese directorio: ";
   cin >> directorio;
    ListarDirectorio(directorio);
        }break;
        case tres:{
    string Archivo;
   cout << "Editando Archivo" << endl;
   cin>>Archivo;
   EditarArchivo(Archivo);
    }break;
    case cuatro:{
   string Arch2;
   cout << "Ingrese directorio: ";
   cin >> Arch2;
    Mostrar(Arch2);
    }break;
    }*/
    /* int uno = str2int("creararchivo");
    int dos = str2int("listararchivos");
    int tres = str2int("modificararchivos");
    int cuatro =str2int("verarchivo");*/
cout<<"Escriba el comando Help para Optener ayuda."<<endl;
    string opcion = " ";
   do{

   cout<<"> ";
    cin>>opcion;
    if(opcion == "creararchivo"){
        string Archivo;
        cout << "Abriendo Archivo" << endl;
        cin>>Archivo;
        CreaArchivo(Archivo);
    }else if(opcion == "listararchivos" ){
        char directorio[100];
        cout << "Ingrese directorio: ";
        cin >> directorio;
        ListarDirectorio(directorio);
    }else if(opcion =="modificararchivo"){
        string Archivo;
        cout << "Editando Archivo" << endl;
        cin>>Archivo;
        EditarArchivo(Archivo);
    }else if(opcion =="verarchivo"){
        string Arch2;
        cout << "Ingrese directorio: ";
        cin >> Arch2;
        Mostrar(Arch2);
    }else if(opcion =="help"){
        Help();
    }


    }while(opcion != "salir");

   system("PAUSE > NULL");
   return 0;
}






