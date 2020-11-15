#include "state_game.h"

state_game::state_game()
{

}

state_game::~state_game()
{

}

void state_game::Init()
{

    vector_enemy.resize(11);
    this->current_bullet = 0;
    bullet_1.Init();
    int k = 2;
    while (k--)
    {
        vector_bullet.push_back(bullet_1);
    }
	hero_1.Init();
	enemy_1.Init();
	gun.Init();
    bar.Init();
    add_1.Init();
    nade_1.Init();
    /*light_1.Init();
    light_2.Init();*/
    collide_1.Init();
    
	face_right = true;
	time = 1;
}



void state_game::Perform(int &score)
{

    int VIEW_HEIGHT = 1000.0f;
    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!",sf::Style::Close| sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1000, 700));


    /*------------------------------------------------------------------------*/
    //map

    sf::Sprite sprite_1;
    sf::Texture texture_1;
    texture_1.loadFromFile("./texture/map/plant_1.png");
    sprite_1.setTexture(texture_1);
    sprite_1.setPosition(100, 100);
    sprite_1.scale(0.1, 0.1);

    sf::Sprite sprite_2;
    sf::Texture texture_2;
    texture_2.loadFromFile("./texture/map/plant_2.png");
    sprite_2.setTexture(texture_2);
    sprite_2.setPosition(1500, 100);
    sprite_2.scale(0.3, 0.3);

    sf::Sprite sprite_3;
    sf::Texture texture_3;
    texture_3.loadFromFile("./texture/map/plant_3.png");
    sprite_3.setTexture(texture_3);
    sprite_3.setPosition(1200, 900);
    sprite_3.scale(0.2, 0.2);

    sf::Texture map_texture;
    map_texture.loadFromFile("./texture/map/map_demo_3.png");
    sf::Sprite map;
    map.setScale(1.5, 1.5);
    map.setTexture(map_texture);
    

    //map react
    sf::Sprite sprite_4;
    sf::Texture texture_4;
    texture_4.loadFromFile("./texture/map/occho.png");
    sprite_4.scale(0.6, 0.6);
    sprite_4.setTexture(texture_4);
    sprite_4.setPosition(100, -80);

    sf::Sprite sprite_5;
    sf::Texture texture_5;
    texture_5.loadFromFile("./texture/map/zombie_4.png");
    sprite_5.scale(0.6, 0.6);
    sprite_5.setTexture(texture_5);
    sprite_5.setPosition(1000, 730);

    sf::Sprite sprite_6;
    sf::Texture texture_6;
    texture_6.loadFromFile("./texture/map/cucai.png");
    sprite_6.scale(0.6, 0.6);
    sprite_6.setTexture(texture_6);
    sprite_6.setPosition(1600, 50);
    
    /*------------------------------------------------------------------------*/
    //score
    sf::Sprite board;
    sf::Texture board_text;
    board_text.loadFromFile("./texture/map/score board.png");
    board.setTexture(board_text);
    board.scale(0.4, 0.3);

    sf::Font font;
    font.loadFromFile("./font/font_bold.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);


    /*------------------------------------------------------------------------------*/
        //process
        while (window.isOpen())
        {
            if (score%100==0 && add_1.IsUse()) //sinh add blood
            {
                add_1.New();
            }
            if (time % 2400 == 0&&vector_enemy.size()<=10) // sinh enemy
            {
                //enemy_1.Die(false);
                vector_enemy.push_back(enemy_1);
                int k = rand() % (4 - 2 + 1) + 2;
                vector_enemy[vector_enemy.size() - 1].Scale(k, k);
            }
            time++;
            sf::Event evnt;
            while (window.pollEvent(evnt))
            {
                switch (evnt.type)
                {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::Resized:
                        float aspecRatio = float(window.getSize().x / float(window.getSize().y));
                        view.setSize(1000 * aspecRatio, 700);
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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N) && bar.IsFull() && time%120 == 0 )
            {
                gun.Change();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                if (current_bullet >= 2) current_bullet = 0;
                vector_bullet[current_bullet].Fire(hero_1.GetPosition(), face_right);
                current_bullet++;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
            {
                nade_1.SetPosition(hero_1.GetPosition(), face_right);
            }

            /*------------------------------------------------------------------------------*/
                //Update
                       
            if (add_1.IsUse()==false && hero_1.GetBody().getGlobalBounds().intersects(add_1.GetBody().getGlobalBounds()))
            {
                hero_1.CollideBlood();
                add_1.Use();
            }
                    
            for (int i = 0; i < vector_enemy.size(); i++)
            {
                 
                 if (!vector_enemy[i].GetBody().getGlobalBounds().intersects(map.getGlobalBounds()))
                 {
                     /*cout << "1" << endl;*/
                     //vector_enemy[i].Die(false);
                     vector_enemy[i].Die(true);
                 }

                 if (vector_enemy[i].GetBody().getGlobalBounds().intersects(vector_bullet[0].GetBody().getGlobalBounds()))
                 {
                      vector_enemy[i].Collide(score);
                      if(!vector_bullet[0].Is_Collide())collide_1.SetPosition(vector_bullet[0].GetPosition(),face_right);
                      vector_bullet[0].Collide();
                      bar.Plus();
                      //light_1.SetPosition(vector_enemy[i].GetPosition());
                      
                      break;
                 }

                 if (vector_enemy[i].GetBody().getGlobalBounds().intersects(vector_bullet[1].GetBody().getGlobalBounds()))
                 {
                      vector_enemy[i].Collide(score);
                      
                      vector_bullet[1].Collide();
                      bar.Plus();
                      //light_2.SetPosition(vector_enemy[i].GetPosition());
                      
                      break;
                 }

                 if (vector_enemy[i].GetBody().getGlobalBounds().intersects(hero_1.GetBody().getGlobalBounds()))
                 {
                      hero_1.Collide();
                 }

                 if (gun.CurrentWeapon() == 1 && vector_enemy[i].GetBody().getGlobalBounds().intersects(gun.GetBody().getGlobalBounds()))
                 {
                     vector_enemy[i].Collide(score);
                 }

                 if (nade_1.IsExplode() && vector_enemy[i].GetBody().getGlobalBounds().intersects(nade_1.GetBody().getGlobalBounds()))
                 {
                     vector_enemy[i].Collide(score);
                     
                 }
            }


            view.setCenter(hero_1.GetPosition());

            /*light_1.Update(hero_1.GetPosition());
            light_2.Update(hero_1.GetPosition());*/
            nade_1.Update();

            collide_1.Update();
            
            add_1.Update();

            hero_1.Update(map,bar.IsFull());

            bar.Update(hero_1.GetPosition());
            if (!bar.IsFull())
            {
                gun.Default();
            }

            gun.Update(hero_1.GetPosition(), face_right);

            for (int i = 0; i < vector_bullet.size(); i++)
            {
                        vector_bullet[i].Update();
            }

            for (int i = 0; i < vector_enemy.size(); i++)
            {
                 if (!vector_enemy[i].IsDie()) vector_enemy[i].Update(hero_1.GetPosition());
                 else vector_enemy.erase(vector_enemy.begin() + i);
            }


        //update score

            board.setPosition(hero_1.GetPosition() + sf::Vector2f(200, -350));
            text.setPosition(hero_1.GetPosition() + sf::Vector2f(230,-350));
            stringstream ss;
            ss << score;
            string s = ss.str();
            string s1 = "SCORE " + s;
            text.setString(s1);

            if (hero_1.IsDie()) window.close();

            window.clear(sf::Color::Black);


            /*------------------------------------------------------------------------------*/
                    //draw

                    window.setView(view);
                    window.draw(map);

     
                    add_1.Draw(window);
                    hero_1.Draw(window);
                    bar.Draw(window); 

                    for (int i = 0; i < vector_bullet.size(); i++)
                    {
                        vector_bullet[i].Draw(window);
                    }
                    
                    /*light_1.Draw(window);
                    light_2.Draw(window);*/

                    for (int i = 0; i < vector_enemy.size(); i++)
                    {
                        vector_enemy[i].Draw(window);
                    }
                    
                    collide_1.Draw(window);
                    
                    nade_1.Draw(window);

                    gun.Draw(window);
                    
                    window.draw(sprite_1);
                    if (hero_1.GetBody().getGlobalBounds().intersects(sprite_4.getGlobalBounds()))
                    {
                        window.draw(sprite_4);
                    }
                    
                    window.draw(sprite_3);
                    if (hero_1.GetBody().getGlobalBounds().intersects(sprite_5.getGlobalBounds()))
                    {
                        window.draw(sprite_5);
                    }
                    
                    window.draw(sprite_2);
                    if (hero_1.GetBody().getGlobalBounds().intersects(sprite_6.getGlobalBounds()))
                    {
                        window.draw(sprite_6);
                    }
                    
                    window.draw(board);
                    window.draw(text);
                    
            window.display();
                       
     }

}