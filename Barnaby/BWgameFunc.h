using namespace std;

int Wait()    //function that makes the program wait, currently unused
{
  using namespace std::chrono_literals;   //setting up the namespace for the clock
  auto start = chrono::high_resolution_clock::now();    //starting clock
  this_thread::sleep_for(1.5s);   //waits 1.5s
  auto end = std::chrono::high_resolution_clock::now();   //ends clock
}

string playerHealth(int Health)   //function to describe monster attacking
{
  string title = "The monster ferociously counter attacks";
  return title;
}

string monsterHealth(int Health)    //function to describe player attacking
{
  string title = "You sliced the monster across the chest";
  return title;
}

string defPlayerHealth(int Health)    //function to describe player blocking
{
  string title = "You just manage to block the monsters attack";
  return title;
}

string playerHealthTotal(int Dmg)   //function to check if player is alive
{
  int batHealth = stoi(accessDatabase("SELECT * FROM Player;", 3, 1));
  int Health = batHealth - Dmg;
  if(Health >= 0)
  {
    return "Your health is "  + to_string(Health);
  }
  else
  {
    return "You are Dead";
  }
}

string monsterHealthTotal(int Dmg)    //function to check if monster is alive
{
  int Health = stoi(accessDatabase("SELECT * FROM Monsters;", 3, 1)) - Dmg;
  return to_string(Health);
}

int ranNum5 ()    //Charlie's rad=ndom function
{
  srand (time(NULL));
  return rand() %5 +1;
}
