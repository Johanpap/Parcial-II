#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>



using namespace std;

struct Node
{
    string output;
    Node* si;
    Node* no;
};

Node* tree;
Node* newNode(string, Node*, Node*);
Node* createBinaryTree();



int main()
{
    //inicia
    sf::RenderWindow window(sf::VideoMode(800, 600), "Filosofia");
    window.setFramerateLimit(60);
 
  

    

    sf::Sprite personaje;
    sf::Texture personaje_text;

    personaje_text.loadFromFile("ant.PNG");
    personaje.setTexture(personaje_text);
  

    sf::Font font;
    if (!font.loadFromFile("Alexandra.otf"))
    {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Filosofia");
 
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);
    text.setPosition(400, 300);
    
/*
    sf::Sprite1 image;
    sf::Texture1 tex;
  
    tex.loadFromFile("antet.PNG");

    image.setTexture(tex);
  */  //Gameloop   
    while (window.isOpen())
    {
        //input
        //leerr cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //cmd
       
        //update
        window.clear();
        //draw
        window.draw(personaje);
        window.draw(text);
        //window.draw(image);
        //window.draw(texto);
        //display
        window.display();
    }

    //liberar juego

    return 0;
    //juego* Juego = new juego(600, 800, "Filosofia");
    /*juego* partida1;
    partida1 = new juego(800, 600, "Dibujar imagenes");
    return 0;
    cout << "Bienvenido, Deseas jugar?" << endl;
    */
}
/*
void juego::gameLoop()
    {
    while (ventana1->isopen())
    {
        dibujar()
    }
    }

void juego::dibujar()
{
    ventana1->clear();
    ventana1->display();
}*/

Node* createBinaryTree() {
    string filosofos[8] =
    {
        "Aristoteles","David hume","Friendri","Immanuel","Jong" ,"Platon"
    };

    string guesses[7] =
    { "Tu Filosofo fue estudiante de platon?","Tu Filosofo anbadono la carrera de leyes?",
    "Tu Filosofo se enfermo de sifilis?","Tu Filosofo fracaso dos veces en intento de una catedra?",
    "Tu Filosofo se destaco en filosofia de politica?","Tu Filosofo tuvo de discipulo Aristoteles?",
    "Tu Filosofo tuvo dos discispulos?"
    };
    Node* answers[8];
    for (int counter = 0; counter < 8; counter++) answers[counter] = newNode(filosofos[counter], NULL, NULL);
   
    Node* questions[7];
    for (int counter = 0; counter < 5; counter++)
        questions[counter] = newNode(guesses[counter], answers[counter * 2], answers[counter * 2 + 1]);

    return questions[6];
}


Node* newNode(string data, Node* left, Node* right)
{
    Node* node = new Node();


    node->output = data;
    node->no = left;
    node->si = right;

    return node;
}


