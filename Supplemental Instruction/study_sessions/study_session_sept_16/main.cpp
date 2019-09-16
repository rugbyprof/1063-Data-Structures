#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool string_match(string big, string small)
{
    int index = big.find(small);
    return index >= 0;
}

string lower_string(string orig)
{
    string result = "";
    for (int i = 0; i < orig.size(); i++)
    {
        result += tolower(orig[i]);
    }
    return result;
}

struct Pokemon
{
    int id;
    string name;
    string type1;
    string type2;
    int hp;
    int atk;
    int def;
    int satk;
    int sdef;
    int spd;
    int gen;
    Pokemon()
    {
        return;
    }
    Pokemon(int nid, string nname, string ntype1, string ntype2, int nhp, int natk, int ndef, int nsatk, int nsdef, int nspd, int ngen)
    {
        id = nid;
        name = nname;
        type1 = ntype1;
        type2 = ntype2;
        hp = nhp;
        atk = natk;
        def = ndef;
        satk = nsatk;
        sdef = nsdef;
        spd = nspd;
        gen = ngen;
    }
    void print()
    {
        cout << id << name << type1 << type2 << hp
             << atk << def << satk << sdef << spd << gen << endl;
    }
};

struct Node
{
    Pokemon poke;
    Node *next;
    Node(Pokemon data, Node *n = NULL)
    {
        poke = data;
        next = n;
    }
};

class List
{
public:
    List()
    {
        head = NULL;
    }
    void push(Pokemon poke)
    {
        Node *temp = new Node(poke, head);
        head = temp;
    }
    Pokemon pop()
    {
        Pokemon result = head->poke;
        Node *temp_del = head;
        head = head->next;
        delete temp_del;
        return result;
    }
    bool find(string pokemon_name)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            //if (temp->poke.name == pokemon_name)
            if (string_match(lower_string(temp->poke.name), lower_string(pokemon_name)))
            {
                return true;
            }
            else
            {
                temp = temp->next;
            }
        }
        return false;
    }

private:
    Node *head;
};

int main()
{
    List pokedex;
    ifstream in;
    in.open("my_pokemon.txt");
    while (!in.eof())
    {
        Pokemon inPkm;
        in >> inPkm.id >> inPkm.name >> inPkm.type1 >> inPkm.type2 >> inPkm.hp >> inPkm.atk >> inPkm.def >> inPkm.satk >> inPkm.sdef >> inPkm.spd >> inPkm.gen;
        pokedex.push(inPkm);
    }

    cout << pokedex.find("Ivysaur") << endl;
    cout << pokedex.find("ivysaur") << endl;
    cout << pokedex.find("Hingle") << endl;
    cout << pokedex.find("saur") << endl;
    cout << pokedex.find("mr.") << endl;
}