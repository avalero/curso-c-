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
  void ladrar() const { cout << "guau" << endl; }
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
  void mauyar() const { cout << "miau" << endl; }
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

  // shared_ptr<Animal> miAnimal = make_shared<Gato>(Gato{"lili"});
  // auto miGato = dynamic_cast<Gato *>(miAnimal.get());
  // miGato->mauyar();

  for (auto animal : animales)
  {
    animal->hago();
    auto unGato = dynamic_cast<Gato *>(animal.get());
    if (unGato)
      unGato->mauyar();
    else
    {
      auto unPerro = dynamic_cast<Perro *>(animal.get());
      if (unPerro)
        unPerro->ladrar();
    }
  }
}