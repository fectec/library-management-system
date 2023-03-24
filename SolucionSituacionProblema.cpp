#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractUsuario
{
    private:

        string Nombre, Genero, Direccion, NumeroTelefono, Correo;
        unsigned short int Edad;
        unsigned int CantidadLibros;

    public:

        virtual void MostrarAtributosUsuario()
        {
            cout<<"\nNOMBRE:\n"<<getNombre();
            cout<<"\n\nGENERO:\n"<<getGenero();
            cout<<"\n\nDIRECCION:\n"<<getDireccion();
            cout<<"\n\nNUMERO DE TELEFONO:\n"<<getNumeroTelefono();
            cout<<"\n\nCORREO:\n"<<getCorreo();
            cout<<"\n\nEDAD:\n"<<getEdad();
            cout<<"\n\nCANTIDAD DE LIBROS:\n"<<getCantidadLibros();
        }

        void setNombre()
        {
            string nombre;

            cout<<"\nNOMBRE:\n";
            cin>>nombre;

            Nombre = nombre;
        }

        string getNombre(){return Nombre;}

        void setGenero()
        {
            string genero;

            cout<<"\nGENERO:\n";
            cin>>genero;

            Genero = genero;
        }

        string getGenero(){return Genero;}

        void setDireccion()
        {
            string direccion;

            cout<<"\nDIRECCION:\n";
            cin>>direccion;

            Direccion = direccion;
        }

        string getDireccion(){return Direccion;}

        void setNumeroTelefono()
        {
            string numero_telefono;

            cout<<"\nNUMERO DE TELEFONO:\n";
            cin>>numero_telefono;

            NumeroTelefono = numero_telefono;
        }

        string getNumeroTelefono(){return NumeroTelefono;}

        void setCorreo()
        {
            string correo;

            cout<<"\nCORREO:\n";
            cin>>correo;

            Correo = correo;
        }

        string getCorreo(){return Correo;}

        void setEdad()
        {
            unsigned short int edad;

            cout<<"\nEDAD:\n";
            cin>>edad;

            Edad = edad;
        }

        unsigned short int getEdad(){return Edad;}

        void setCantidadLibros()
        {
            CantidadLibros = 0;
        }

        unsigned int getCantidadLibros(){return CantidadLibros;}

        void ObtenerLibro()
        {
            CantidadLibros++;
        }

        AbstractUsuario()
        {
            setNombre();
            setGenero();
            setDireccion();
            setNumeroTelefono();
            setCorreo();
            setEdad();
            setCantidadLibros();
        }
};

class Alumno: public AbstractUsuario
{
    private:

        string Matricula, Carrera;

    public:

        void MostrarAtributosUsuario()
        {
            AbstractUsuario::MostrarAtributosUsuario();

            cout<<"\n\nMATRICULA:\n"<<getMatricula();
            cout<<"\n\nCARRERA:\n"<<getCarrera()<<endl;
        }

        void setMatricula()
        {
            string matricula;

            cout<<"\nMATRICULA:\n";
            cin>>matricula;

            Matricula = matricula;
        }

        string getMatricula(){return Matricula;}

        void setCarrera()
        {
            string carrera;

            cout<<"\nCARRERA:\n";
            cin>>carrera;

            Carrera = carrera;
        }

        string getCarrera(){return Carrera;}

        Alumno():AbstractUsuario()
        {
            setMatricula();
            setCarrera();
        }
};

class Profesor: public AbstractUsuario
{
    private:

        string TituloProfesional, Departamento;

    public:

        void MostrarAtributosUsuario()
        {
            AbstractUsuario::MostrarAtributosUsuario();

            cout<<"\n\nTITULO PROFESIONAL:\n"<<getTituloProfesional();
            cout<<"\n\nDEPARTAMENTO:\n"<<getDepartamento()<<endl;
        }

        void setTituloProfesional()
        {
            string titulo_profesional;

            cout<<"\nTITULO PROFESIONAL:\n";
            cin>>titulo_profesional;

            TituloProfesional = titulo_profesional;
        }

        string getTituloProfesional(){return TituloProfesional;}

        void setDepartamento()
        {
            string departamento;

            cout<<"\nDEPARTAMENTO:\n";
            cin>>departamento;

            Departamento = departamento;
        }

        string getDepartamento(){return Departamento;}

        Profesor():AbstractUsuario()
        {
            setTituloProfesional();
            setDepartamento();
        }
};

class AbstractLibro
{
    private:

        string Autor, Titulo, Editorial;
        unsigned short int AnoPublicacion;

    public:

        virtual void MostrarAtributosLibro()
        {
            cout<<"\nAUTOR:\n"<<getAutor();
            cout<<"\n\nTITULO:\n"<<getTitulo();
            cout<<"\n\nEDITORIAL:\n"<<getEditorial();
            cout<<"\n\nANO DE PUBLICACION:\n"<<getAnoPublicacion();
        }

        void setAutor()
        {
            string autor;

            cout<<"\nAUTOR:\n";
            cin>>autor;

            Autor = autor;
        }

        string getAutor(){return Autor;}

        void setTitulo()
        {
            string titulo;

            cout<<"\nTITULO:\n";
            cin>>titulo;

            Titulo = titulo;
        }

        string getTitulo(){return Titulo;}

        void setEditorial()
        {
            string editorial;

            cout<<"\nEDITORIAL:\n";
            cin>>editorial;

            Editorial = editorial;
        }

        string getEditorial(){return Editorial;}

        void setAnoPublicacion()
        {
            unsigned short int ano_publicacion;

            cout<<"\nANO DE PUBLICACION:\n";
            cin>>ano_publicacion;

            AnoPublicacion = ano_publicacion;
        }

        unsigned short int getAnoPublicacion(){return AnoPublicacion;}

        AbstractLibro()
        {
            setAutor();
            setTitulo();
            setEditorial();
            setAnoPublicacion();
        }
};

class LibroImpreso: public AbstractLibro
{
    private:

        bool Estado;

    public:

        void MostrarAtributosLibro()
        {
            AbstractLibro::MostrarAtributosLibro();

            cout<<"\n\nPRESTADO:\n";

            if(getEstado() == true)
            {
                cout<<"SI"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }

        void setEstado()
        {
            Estado = false;
        }

        bool getEstado(){return Estado;}

        void Prestado()
        {
            Estado = true;
        }

        LibroImpreso():AbstractLibro()
        {
            setEstado();
        }
};

class LibroEnLinea: public AbstractLibro
{
    private:

        string URL;

    public:

        void MostrarAtributosLibro()
        {
            AbstractLibro::MostrarAtributosLibro();

            cout<<"\n\nURL:\n"<<getURL()<<endl;
        }

        void setURL()
        {
            string url;

            cout<<"\nURL:\n";
            cin>>url;

            URL = url;
        }

        string getURL(){return URL;}

        LibroEnLinea():AbstractLibro(){setURL();}
};

class SistemaBiblioteca
{
    public:

        void DesplegarMenuPrincipal(vector<Alumno>& Alumnos, vector<Profesor>& Profesores, vector<LibroImpreso>& LibrosImpresos, vector<LibroEnLinea>& LibrosEnLinea)
        {
            unsigned short int opcion = 0;

            cout<<"\tSISTEMA INTEGRADO DE GESTION BIBLIOTECARIA\n";

            while(opcion != 4)
            {
                cout<<"\n1. ANADIR\n2. MOSTRAR\n3. PRESTAMO\n4. SALIR\n\n";
                cin>>opcion;

                if(opcion == 1){MenuAnadir(Alumnos, Profesores, LibrosImpresos, LibrosEnLinea);}
                else if(opcion == 2){MenuMostrar(Alumnos, Profesores, LibrosImpresos, LibrosEnLinea);}
                else if(opcion == 3){MenuPrestamo(Alumnos, Profesores, LibrosImpresos, LibrosEnLinea);}
                else if(opcion != 4){cout<<"\nERROR\n";}
            }
        }

        void MenuAnadir(vector<Alumno>& Alumnos, vector<Profesor>& Profesores, vector<LibroImpreso>& LibrosImpresos, vector<LibroEnLinea>& LibrosEnLinea)
        {
            unsigned short int opcion = 3;

            while(opcion != 0)
            {
                cout<<"\n0. REGRESAR AL MENU PRINCIPAL\n1. USUARIO\n2. LIBRO\n\n";
                cin>>opcion;

                if(opcion == 1){MenuAnadirUsuario(Alumnos, Profesores);}
                else if(opcion == 2){MenuAnadirLibro(LibrosImpresos, LibrosEnLinea);}
                else if(opcion != 0){cout<<"\nERROR\n";}
            }
        }

        void MenuAnadirUsuario(vector<Alumno>& Alumnos, vector<Profesor>& Profesores)
        {
            unsigned short int opcion = 3;

            while(opcion != 0)
            {
                cout<<"\n0. REGRESAR\n1. ALUMNO\n2. PROFESOR\n\n";
                cin>>opcion;

                if(opcion == 1)
                {
                    Alumno NuevoAlumno = Alumno();
                    Alumnos.push_back(NuevoAlumno);
                }
                else if(opcion == 2)
                {
                    Profesor NuevoProfesor = Profesor();
                    Profesores.push_back(NuevoProfesor);
                }
                else if(opcion != 0)
                {
                    cout<<"\nERROR\n";
                }
            }
        }

        void MenuAnadirLibro(vector<LibroImpreso>& LibrosImpresos, vector<LibroEnLinea>& LibrosEnLinea)
        {
            unsigned short int opcion = 3;

            while(opcion != 0)
            {
                cout<<"\n0. REGRESAR\n1. LIBRO IMPRESO\n2. LIBRO EN LINEA\n\n";
                cin>>opcion;

                if(opcion == 1)
                {
                    LibroImpreso NuevoLibroImpreso = LibroImpreso();
                    LibrosImpresos.push_back(NuevoLibroImpreso);
                }
                else if(opcion == 2)
                {
                    LibroEnLinea NuevoLibroEnLinea = LibroEnLinea();
                    LibrosEnLinea.push_back(NuevoLibroEnLinea);
                }
                else if(opcion != 0)
                {
                    cout<<"\nERROR\n";
                }
            }
        }

        void MenuMostrar(vector<Alumno>& Alumnos, vector<Profesor>& Profesores, vector<LibroImpreso>& LibrosImpresos, vector<LibroEnLinea>& LibrosEnLinea)
        {
            unsigned short int opcion = 3;

            while(opcion != 0)
            {
                cout<<"\n0. REGRESAR AL MENU PRINCIPAL\n1. USUARIOS\n2. LIBROS\n\n";
                cin>>opcion;

                if(opcion == 1){MenuMostrarUsuarios(Alumnos, Profesores);}
                else if(opcion == 2){MenuMostrarLibros(LibrosImpresos, LibrosEnLinea);}
                else if(opcion != 0){cout<<"\nERROR\n";}
            }
        }

        void MenuMostrarUsuarios(vector<Alumno>& Alumnos, vector<Profesor>& Profesores)
        {
            unsigned short int opcion = 3;

            while(opcion != 0)
            {
                cout<<"\n0. REGRESAR\n1. ALUMNOS\n2. PROFESORES\n\n";
                cin>>opcion;

                if(opcion == 1)
                {
                    if(Alumnos.size() == 0)
                    {
                        cout<<"\nERROR\n";
                    }
                    else
                    {
                        for(unsigned int i = 0; i < Alumnos.size(); i++)
                        {
                            cout<<endl<<i + 1<<"."<<endl;
                            Alumnos[i].MostrarAtributosUsuario();
                        }
                    }
                }
                else if(opcion == 2)
                {
                    if(Profesores.size() == 0)
                    {
                        cout<<"\nERROR\n";
                    }
                    else
                    {
                        for(unsigned int i = 0; i < Profesores.size(); i++)
                        {
                            cout<<endl<<i + 1<<"."<<endl;
                            Profesores[i].MostrarAtributosUsuario();
                        }
                    }
                }
                else if(opcion != 0)
                {
                    cout<<"\nERROR\n";
                }
            }
        }

        void MenuMostrarLibros(vector<LibroImpreso>& LibrosImpresos, vector<LibroEnLinea>& LibrosEnLinea)
        {
            unsigned short int opcion = 3;

            while(opcion != 0)
            {
                cout<<"\n0. REGRESAR\n1. LIBROS IMPRESOS\n2. LIBROS EN LINEA\n\n";
                cin>>opcion;

                if(opcion == 1)
                {
                    if(LibrosImpresos.size() == 0)
                    {
                        cout<<"\nERROR\n";
                    }
                    else
                    {
                        for(unsigned int i = 0; i < LibrosImpresos.size(); i++)
                        {
                            cout<<endl<<i + 1<<"."<<endl;
                            LibrosImpresos[i].MostrarAtributosLibro();
                        }
                    }
                }
                else if(opcion == 2)
                {
                    if(LibrosEnLinea.size() == 0)
                    {
                        cout<<"\nERROR\n";
                    }
                    else
                    {
                        for(unsigned int i = 0; i < LibrosEnLinea.size(); i++)
                        {
                            cout<<endl<<i + 1<<"."<<endl;
                            LibrosEnLinea[i].MostrarAtributosLibro();
                        }
                    }
                }
                else if(opcion != 0)
                {
                    cout<<"\nERROR\n";
                }
            }
        }

        void MenuPrestamo(vector<Alumno>& Alumnos, vector<Profesor>& Profesores, vector<LibroImpreso>& LibrosImpresos, vector<LibroEnLinea>& LibrosEnLinea)
        {
            if(LibrosImpresos.size() == 0)
            {
                cout<<"\nERROR\n";
            }
            else
            {
                unsigned int contador = 0;

                for(unsigned int i = 0; i < LibrosImpresos.size(); i++)
                {
                    if(LibrosImpresos[i].getEstado() == true)
                    {
                        contador++;
                    }
                }
                if(contador == LibrosImpresos.size())
                {
                    cout<<"\nNO HAY LIBROS IMPRESOS DISPONIBLES PARA PRESTAMO\n";
                }
                else
                {
                    unsigned short int opcion = 3;

                    while(opcion != 0)
                    {
                        cout<<"\n0. REGRESAR AL MENU PRINCIPAL\n1. PRESTAMO PARA ALUMNO\n2. PRESTAMO PARA PROFESOR\n\n";
                        cin>>opcion;

                        if(opcion == 1)
                        {
                            if(Alumnos.size() == 0)
                            {
                                cout<<"\nERROR\n";
                            }
                            else
                            {
                                unsigned int NumeroUsuario, NumeroLibroImpreso;

                                cout<<"\nINTRODUCE EL NUMERO DEL ALUMNO QUE SOLICITA EL PRESTAMO\n"<<endl;
                                cin>>NumeroUsuario;

                                while(NumeroUsuario <= 0 || NumeroUsuario > Alumnos.size())
                                {
                                    cout<<"\nERROR\n\n";
                                    cin>>NumeroUsuario;
                                }

                                cout<<"\nINTRODUCE EL NUMERO DEL LIBRO IMPRESO QUE SOLICITA EL ALUMNO\n"<<endl;
                                cin>>NumeroLibroImpreso;

                                while(NumeroLibroImpreso <= 0 || NumeroLibroImpreso > LibrosImpresos.size())
                                {
                                    cout<<"\nERROR\n\n";
                                    cin>>NumeroLibroImpreso;
                                }

                                if(LibrosImpresos[NumeroLibroImpreso - 1].getEstado() == true)
                                {
                                    cout<<"\nESTE LIBRO IMPRESO YA FUE PRESTADO\n";
                                }
                                else
                                {
                                    LibrosImpresos[NumeroLibroImpreso - 1].Prestado();
                                    Alumnos[NumeroUsuario - 1].ObtenerLibro();
                                }
                            }
                        }
                        else if(opcion == 2)
                        {
                            if(Profesores.size() == 0)
                            {
                                cout<<"\nERROR\n";
                            }
                            else
                            {
                                unsigned int NumeroUsuario, NumeroLibroImpreso;

                                cout<<"\nINTRODUCE EL NUMERO DEL PROFESOR QUE SOLICITA EL PRESTAMO\n"<<endl;
                                cin>>NumeroUsuario;

                                while(NumeroUsuario <= 0 || NumeroUsuario > Profesores.size())
                                {
                                    cout<<"\nERROR\n\n";
                                    cin>>NumeroUsuario;
                                }

                                cout<<"\nINTRODUCE EL NUMERO DEL LIBRO IMPRESO QUE SOLICITA EL PROFESOR\n"<<endl;
                                cin>>NumeroLibroImpreso;

                                while(NumeroLibroImpreso <= 0 || NumeroLibroImpreso > LibrosImpresos.size())
                                {
                                    cout<<"\nERROR\n\n";
                                    cin>>NumeroLibroImpreso;
                                }

                                if(LibrosImpresos[NumeroLibroImpreso - 1].getEstado() == true)
                                {
                                    cout<<"\nESTE LIBRO IMPRESO YA FUE PRESTADO\n";
                                }
                                else
                                {
                                    LibrosImpresos[NumeroLibroImpreso - 1].Prestado();
                                    Profesores[NumeroUsuario - 1].ObtenerLibro();
                                }
                            }
                        }
                        else if(opcion != 0)
                        {
                            cout<<"\nERROR\n\n";
                        }
                    }
                }
            }
        }
};

int main()
{
    vector<Alumno> Alumnos;
    vector<Profesor> Profesores;
    vector<LibroImpreso> LibrosImpresos;
    vector<LibroEnLinea> LibrosEnLinea;

    SistemaBiblioteca Tec_De_Monterrey;
    Tec_De_Monterrey.DesplegarMenuPrincipal(Alumnos, Profesores, LibrosImpresos, LibrosEnLinea);

    return 0;
}
