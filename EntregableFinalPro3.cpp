#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> // Para setw

using namespace std;

// Definicion de la clase base Entidad
class Entidad {
protected:
	int id; // Identificador de la entidad
	
public:
	Entidad(int id) : id(id) {} // Constructor que inicializa el ID
	virtual ~Entidad() {} // Destructor virtual para permitir el polimorfismo
	
	// Metodo virtual puro para imprimir los detalles de la entidad
	virtual void imprimirDetalles(bool formatoLista) const = 0;
	
	// Metodo virtual puro para buscar la entidad por nombre
	virtual bool buscarPorNombre(const string& nombreApellido) const = 0;
};

// Definicion de la clase Libro que hereda de Entidad
class Libro : public Entidad {
private:
	string title;
	string author;
	string ISBN;
	int publicationYear;
	int pages;
	string genre;
	string publisher;
	
public:
	// Constructor para inicializar los atributos del libro
	Libro(int id, const string& title, const string& author, const string& ISBN,
		  int publicationYear, int pages, const string& genre, const string& publisher)
		: Entidad(id), title(title), author(author), ISBN(ISBN),
		publicationYear(publicationYear), pages(pages), genre(genre), publisher(publisher) {}
	
	// Constructor adicional para facilitar la generacion aleatoria
	Libro(int id) : Entidad(id) {}
	
	// Metodo para imprimir los detalles del libro
	void imprimirDetalles(bool formatoLista) const override {
		if (formatoLista) {
			// Imprimir en formato de lista
			cout << "ID: " << id << ", Titulo: " << title << ", Autor: " << author
				<< ", ISBN: " << ISBN << ", Ano de publicacion: " << publicationYear
				<< ", Paginas: " << pages << ", Genero: " << genre << ", Editorial: " << publisher << endl;
			cout << endl; // Agrega un espacio de separacion adicional entre cada libro en formato lista
		} else {
			// Imprimir en formato de bloque
			cout << "+-------+----------------------------+-------------------------------+---------------------+" << endl;
			cout << "|   ID  |           Titulo           |            Autor              |       ISBN          |" << endl;
			cout << "+-------+----------------------------+-------------------------------+---------------------+" << endl;
			cout << "| " << setw(6) << id << " | " << setw(26) << title << " | " << setw(29) << author << " | " << setw(19) << ISBN << " |" << endl;
			cout << "+-------+----------------------------+-------------------------------+---------------------+" << endl;
			cout << "| Ano de publicacion: " << setw(4) << publicationYear << " | Paginas: " << setw(3) << pages << " | Genero: " << setw(11) << genre << " | Editorial: " << setw(13) << publisher << " |" << endl;
			cout << "+------------------------------------------------------------+---------------------+" << endl;
		}
	}
	
	// Metodo para buscar el libro por nombre
	bool buscarPorNombre(const string& nombreTitulo) const override {
		string tituloMinusculas = title;
		transform(tituloMinusculas.begin(), tituloMinusculas.end(), tituloMinusculas.begin(), ::tolower);
		string nombreTituloMinusculas = nombreTitulo;
		transform(nombreTituloMinusculas.begin(), nombreTituloMinusculas.end(), nombreTituloMinusculas.begin(), ::tolower);
		return tituloMinusculas.find(nombreTituloMinusculas) != string::npos;
	}
};

// Definicion de la clase Usuario que hereda de Entidad
class Usuario : public Entidad {
private:
	string name;
	string lastname;
	string email;
	int age;
	
public:
	// Constructor para inicializar los atributos del usuario
	Usuario(int id, const string& name, const string& lastname, const string& email, int age)
		: Entidad(id), name(name), lastname(lastname), email(email), age(age) {}
	
	// Constructor adicional para facilitar la generacion aleatoria
	Usuario(int id) : Entidad(id) {}
	
	// Metodo para imprimir los detalles del usuario
	void imprimirDetalles(bool formatoLista) const override {
		if (formatoLista) {
			// Imprimir en formato de lista
			cout << "ID: " << id << ", Nombre: " << name << ", Apellido: " << lastname
				<< ", Email: " << email << ", Edad: " << age << endl;
			cout << endl; // Agrega un espacio de separacion adicional entre cada usuario en formato lista
		} else {
			// Imprimir en formato de bloque
			cout << "+-------+----------------------+----------------------+-----------------+" << endl;
			cout << "|   ID  |        Nombre        |       Apellido       |      Email      |" << endl;
			cout << "+-------+----------------------+----------------------+-----------------+" << endl;
			cout << "| " << setw(6) << id << " | " << setw(20) << name << " | " << setw(20) << lastname << " | " << setw(15) << email << " |" << endl;
			cout << "+-------------------------------------------------------+-----------------+" << endl;
			cout << "| Edad: " << setw(3) << age << " |" << setw(52) << " |" << endl;
			cout << "+-------------------------------------------------------+-----------------+" << endl;
		}
	}
	
	// Metodo para buscar al usuario por nombre o apellido
	bool buscarPorNombre(const string& nombreApellido) const override {
		string nombreCompleto = name + " " + lastname;
		string nombreCompletoMinusculas = nombreCompleto;
		transform(nombreCompletoMinusculas.begin(), nombreCompletoMinusculas.end(), nombreCompletoMinusculas.begin(), ::tolower);
		string nombreApellidoMinusculas = nombreApellido;
		transform(nombreApellidoMinusculas.begin(), nombreApellidoMinusculas.end(), nombreApellidoMinusculas.begin(), ::tolower);
		return nombreCompletoMinusculas.find(nombreApellidoMinusculas) != string::npos;
	}
};

// Definicion de la clase Bibliotecario que hereda de Entidad
class Bibliotecario : public Entidad {
private:
	string name;
	string lastname;
	string email;
	int experienceYears;
	
public:
	// Constructor para inicializar los atributos del bibliotecario
	Bibliotecario(int id, const string& name, const string& lastname, const string& email, int experienceYears)
		: Entidad(id), name(name), lastname(lastname), email(email), experienceYears(experienceYears) {}
	
	// Constructor adicional para facilitar la generacion aleatoria
	Bibliotecario(int id) : Entidad(id) {}
	
	// Metodo para imprimir los detalles del bibliotecario
	void imprimirDetalles(bool formatoLista) const override {
		if (formatoLista) {
			// Imprimir en formato de lista
			cout << "ID: " << id << ", Nombre: " << name << ", Apellido: " << lastname
				<< ", Email: " << email << ", Anos de experiencia: " << experienceYears << endl;
			cout << endl; // Agrega un espacio de separacion adicional entre cada bibliotecario en formato lista
		} else {
			// Imprimir en formato de bloque
			cout << "+-------+----------------------+----------------------+-----------------+" << endl;
			cout << "|   ID  |        Nombre        |       Apellido       |      Email      |" << endl;
			cout << "+-------+----------------------+----------------------+-----------------+" << endl;
			cout << "| " << setw(6) << id << " | " << setw(20) << name << " | " << setw(20) << lastname << " | " << setw(15) << email << " |" << endl;
			cout << "+-------------------------------------------------------+-----------------+" << endl;
			cout << "| Anos de experiencia: " << setw(3) << experienceYears << " |" << setw(45) << " |" << endl;
			cout << "+-------------------------------------------------------+-----------------+" << endl;
		}
	}
	
	// Metodo para buscar al bibliotecario por nombre o apellido
	bool buscarPorNombre(const string& nombreApellido) const override {
		string nombreCompleto = name + " " + lastname;
		string nombreCompletoMinusculas = nombreCompleto;
		transform(nombreCompletoMinusculas.begin(), nombreCompletoMinusculas.end(), nombreCompletoMinusculas.begin(), ::tolower);
		string nombreApellidoMinusculas = nombreApellido;
		transform(nombreApellidoMinusculas.begin(), nombreApellidoMinusculas.end(), nombreApellidoMinusculas.begin(), ::tolower);
		return nombreCompletoMinusculas.find(nombreApellidoMinusculas) != string::npos;
	}
};

// Clase gestora de entidades
template<class T>
class GestorEntidades {
private:
	vector<T> entidades; // Vector para almacenar las entidades
	
public:
	// Metodo para agregar una entidad al vector
	void agregarEntidad(const T& entidad) {
		entidades.push_back(entidad);
	}
	
	// Metodo para buscar entidades por nombre
	bool buscarPorNombre(const string& nombre, bool formatoLista) {
		vector<T> coincidencias; // Vector para almacenar las coincidencias encontradas
		for (const auto& entidad : entidades) {
			if (entidad.buscarPorNombre(nombre)) {
				coincidencias.push_back(entidad); // Agregar entidad al vector de coincidencias
			}
		}
		if (!coincidencias.empty()) {
			// Imprimir las coincidencias encontradas
			cout << "\nCoincidencias encontradas:" << endl;
			for (const auto& entidad : coincidencias) {
				entidad.imprimirDetalles(formatoLista);
			}
			return true;
		} else {
			cout << "No se encontraron coincidencias." << endl;
			return false;
		}
	}
};

// Funcion para generar un codigo de 5 digitos aleatorio
inline int generarCodigoAleatorio() {
	return rand() % 90000 + 10000; // Genera un numero aleatorio entre 10000 y 99999
}

// Funcion para generar datos aleatorios para libros, usuarios y bibliotecarios
void generarDatosAleatorios(GestorEntidades<Libro>& gestorLibros, GestorEntidades<Usuario>& gestorUsuarios, GestorEntidades<Bibliotecario>& gestorBibliotecarios, int cantidad) {
	// Arrays fijos de nombres y apellidos
	string nombres[] = {"Juan", "Maria", "Luis", "Ana", "Pedro", "Laura", "Carlos", "Sofia", "Diego", "Elena"};
	string apellidos[] = {"Gomez", "Martinez", "Lopez", "Perez", "Rodriguez", "Sanchez", "Fernandez", "Garcia", "Moreno", "Navarro"};
	
	// Arrays de datos fijos para utilizar en la generacion aleatoria
	string titulos[] = {
		"El Alquimista", "La Sombra del Viento", "Los Juegos del Hambre", "El enigma de Fermat", "Cien anos de soledad", "Orgullo y prejuicio", "El codigo Da Vinci", "La cabana", "El principito", "Matar a un ruisenor"};
	
	string autores[] = {
		"Simon Singh", "Carlos Ruiz Zafon", "Suzanne Collins", "George Orwell", "Makoto Shinkai", "Gabriel Garcia Marquez", "J.K. Rowling", "George Orwell", "Jane Austen", "Dan Brown"};
	
	string generos[] = {
		"Fantasia", "Misterio", "Aventura", "Ciencia", "Comedia", "Romance", "Thriller", "Drama", "Terror", "Historia"};
	
	string editoriales[] = {
		"Algar", "Corimbo", "Alba", "Alianza", "Lumen", "Planeta", "Anagrama", "Debolsillo", "Penguin Random House", "Austral"};
	
	// Generacion de datos aleatorios para cada entidad
	for (int i = 0; i < cantidad; ++i) {
		// Generacion de nombres y apellidos aleatorios
		string nombreUsuario = nombres[rand() % 10];
		string apellidoUsuario = apellidos[rand() % 10];
		string nombreBibliotecario = nombres[rand() % 10];
		string apellidoBibliotecario = apellidos[rand() % 10];
		
		// Agregar una nueva entidad de libro al gestor de libros
		gestorLibros.agregarEntidad(Libro(generarCodigoAleatorio(), titulos[rand() % 10], autores[rand() % 10], to_string(generarCodigoAleatorio()), rand() % 54 + 1970, rand() % 400 + 100, generos[rand() % 10], editoriales[rand() % 10]));
		
		// Agregar una nueva entidad de usuario al gestor de usuarios
		gestorUsuarios.agregarEntidad(Usuario(generarCodigoAleatorio(), nombreUsuario, apellidoUsuario, "email" + to_string(i + 1) + "@example.com", 20 + i * 5));
		
		// Agregar una nueva entidad de bibliotecario al gestor de bibliotecarios
		gestorBibliotecarios.agregarEntidad(Bibliotecario(generarCodigoAleatorio(), nombreBibliotecario, apellidoBibliotecario, "biblio" + to_string(i + 1) + "@library.com", i + 1));
	}
}

// Funcion para mostrar el menu principal
char mostrarMenu() {
	char opcion;
	cout << "\nMENU:" << endl;
	cout << "1) Llenado de datos" << endl;
	cout << "2) Listados" << endl;
	cout << "3) Busquedas" << endl;
	cout << "0) Salir" << endl;
	cout << "Ingrese una opcion: ";
	cin >> opcion;
	return opcion;
}

int main() {
	const int cantidad = 10; // Cambiado el numero de entidades a generar a 10 por cada tipo
	GestorEntidades<Libro> gestorLibros;
	GestorEntidades<Usuario> gestorUsuarios;
	GestorEntidades<Bibliotecario> gestorBibliotecarios;
	
	char opcion;
	bool datosGenerados = false; // Bandera para controlar si se han generado datos
	
	do {
		opcion = mostrarMenu(); // Mostrar el menu principal
		
		switch (opcion) {
		case '1':
			// Llenado de datos aleatorios
			generarDatosAleatorios(gestorLibros, gestorUsuarios, gestorBibliotecarios, cantidad);
			cout << "Datos generados aleatoriamente." << endl;
			datosGenerados = true;
			break;
			
		case '2':
			// Submenu de listados
			if (datosGenerados) {
				char opcionListados;
				cout << "Seleccione el formato de listado (l: Lista, b: Bloque): ";
				cin >> opcionListados;
				bool formatoLista = (opcionListados == 'l' || opcionListados == 'L');
				do {
					cout << "\nSUBMENU LISTADOS:" << endl;
					cout << "a) Listado de Libros" << endl;
					cout << "b) Listado de Usuarios" << endl;
					cout << "c) Listado de Bibliotecarios" << endl;
					cout << "x) Salir" << endl;
					cout << "Ingrese una opcion: ";
					cin >> opcionListados;
					
					switch (opcionListados) {
					case 'a':
						cout << "\nLista de Libros:" << endl;
						gestorLibros.buscarPorNombre("", formatoLista);
						break;
						
					case 'b':
						cout << "\nLista de Usuarios:" << endl;
						gestorUsuarios.buscarPorNombre("", formatoLista);
						break;
						
					case 'c':
						cout << "\nLista de Bibliotecarios:" << endl;
						gestorBibliotecarios.buscarPorNombre("", formatoLista);
						break;
						
					case 'x':
						break;
						
					default:
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				} while (opcionListados != 'x');
			} else {
				cout << "No hay datos generados. Por favor, genere datos primero." << endl;
			}
			break;
			
		case '3':
			// Submenu de busquedas
			if (datosGenerados) {
				char opcionBusquedas;
				do {
					cout << "\nSUBMENU BUSQUEDAS:" << endl;
					cout << "a) Busqueda de Libro (Titulo)" << endl;
					cout << "b) Busqueda de Usuario (Nombre o Apellido)" << endl;
					cout << "c) Busqueda de Bibliotecario (Nombre o Apellido)" << endl;
					cout << "x) Salir" << endl;
					cout << "Ingrese una opcion: ";
					cin >> opcionBusquedas;
					
					switch (opcionBusquedas) {
					case 'a': {
						string titulo;
						cout << "Ingrese el titulo del libro a buscar: ";
						cin.ignore(); // Limpiar el buffer del teclado
						getline(cin, titulo);
						cout << "\nLista de Libros:" << endl;
						gestorLibros.buscarPorNombre(titulo, true);
						break;
					}
					
					case 'b': {
						string nombreApellido;
						cout << "Ingrese el nombre o apellido del usuario a buscar: ";
						cin >> nombreApellido;
						cout << "\nLista de Usuarios:" << endl;
						gestorUsuarios.buscarPorNombre(nombreApellido, true);
						break;
					}
					
					case 'c': {
						string nombreApellido;
						cout << "Ingrese el nombre o apellido del bibliotecario a buscar: ";
						cin >> nombreApellido;
						cout << "\nLista de Bibliotecarios:" << endl;
						gestorBibliotecarios.buscarPorNombre(nombreApellido, true);
						break;
					}
					
					case 'x':
						break;
						
					default:
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				} while (opcionBusquedas != 'x');
			} else {
				cout << "No hay datos generados. Por favor, genere datos primero." << endl;
			}
			break;
			
		case '0':
			cout << "Saliendo del programa..." << endl;
			break;
			
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcion != '0');
	
	return 0;
}

