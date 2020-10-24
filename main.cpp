#include <SFML/Graphics.hpp>
#include "hero.h"
#include "enemy.h"
#include "bullet.h"
#include "weapon.h"
using namespace std;
static int VIEW_HEIGHT = 700.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspecRatio = float(window.getSize().x / float(window.getSize().y));
    view.setSize(VIEW_HEIGHT * aspecRatio, VIEW_HEIGHT);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!",sf::Style::Close| sf::Style::Resize);   
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("Attack (78x58).png");
    sprite.setTexture(texture);

/*------------------------------------------------------------------------------*/
    //init

    vector <enemy> vector_enemy;
    
    hero hero_1(0.2f);
    hero_1.Init();

    weapon gun;
    gun.Init();

    vector <bullet> bullet_list;
    bullet bullet_1;
    bullet_1.Init();
    /*for (int i = 0; i <= 20; i++)
    {
        bullet_list.push_back(bullet_1);
    }*/
    int current_bullet = 0;

    enemy enemy_1(0.0005f);
    enemy_1.Init();


    bool face_right=true;
    int dem = 0;



/*------------------------------------------------------------------------------*/
    //process


    while (window.isOpen())
    {
        if (dem % 3600 == 0)
        {
            vector_enemy.push_back(enemy_1);
        }
        dem++;
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    ResizeView(window, view);
                    break; 
            }
        }

        if (sf::Event::KeyReleased)
        {
            hero_1.Idle();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            hero_1.MoveLeft();
            face_right = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            hero_1.MoveRight();
            face_right = 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            hero_1.MoveUp();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            hero_1.MoveDown();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
        {
            hero_1.Fight();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
        {
            gun.Change();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            bullet_1.Fire(hero_1.GetPosition(), face_right);
        }


/*------------------------------------------------------------------------------*/
    //Update


        /*if (enemy_1.GetBody().getGlobalBounds().intersects(bullet_1.GetBody().getGlobalBounds()))
        {
            enemy_1.Die(true);
        }*/

        for (int i = 0; i < vector_enemy.size(); i++)
        {
            if (vector_enemy[i].GetBody().getGlobalBounds().intersects(bullet_1.GetBody().getGlobalBounds()))
            {
                vector_enemy[i].Die(true);
                bullet_1.Collide();
                break;
            }
        }


        view.setCenter(hero_1.GetPosition());

        hero_1.Update();

        gun.Update(hero_1.GetPosition(), face_right);

        bullet_1.Update();
        /*if(!enemy_1.IsDie()) enemy_1.Update(hero_1.GetPosition());*/
        for (int i = 0; i < vector_enemy.size(); i++)
        {
            if (!vector_enemy[i].IsDie()) vector_enemy[i].Update(hero_1.GetPosition());
            else vector_enemy.erase(vector_enemy.begin() + i);
        }

      
        
        window.clear(sf::Color(150,150,24));





/*------------------------------------------------------------------------------*/
        //draw
        window.setView(view);
        hero_1.Draw(window);
        gun.Draw(window);
        
        bullet_1.Draw(window);
        
        /*if(!enemy_1.IsDie())enemy_1.Draw(window);*/
        for (int i = 0; i < vector_enemy.size(); i++)
        {
            if(!vector_enemy[i].IsDie()) vector_enemy[i].Draw(window);
        }
        window.draw(sprite);
        window.display();
    }

    return 0;
}