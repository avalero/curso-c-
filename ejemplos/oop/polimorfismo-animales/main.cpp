#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Animal
{
public:
  Animal() = default;
  Animal(string nombre);
  virtual ~Animal() = default;

  virtual void hago() const = 0;

protected:
  string nombre;
};

Animal::Animal(string nombre) : nombre{nombre}
{
}

class Perro : public Animal
{
public:
  Perro(string nombre) : Animal{nombre} {}
  void hago() const override;
};

void Perro::hago() const
{
  cout << "Soy " << nombre << " y hago guau"
       << endl;
}

class Gato : public Animal
{
public:
  Gato(string nombre) : Animal{nombre} {}
  void hago() const override;
};

void Gato::hago() const
{
  cout << "Soy " << nombre << " y hago miau"
       << endl;
}

int main()
{
  // Animal miAnimal{"lili"};
  // Perro miPerro("pippin");
  // Gato miGato("sherlock");
  // vector<Animal> animales;
  // // animales.push_back(miAnimal);
  // animales.push_back(miPerro);
  // animales.push_back(miGato);

  // Animal otroAnimal = miGato;
  // otroAnimal.hago();

  vector<shared_ptr<Animal>> animales;
  animales.push_back(make_shared<Gato>(Gato{"sherlock"}));
  animales.push_back(make_shared<Perro>(Perro{"pippin"}));
  for (auto animal : animales)
  {
    animal->hago();
  }
}