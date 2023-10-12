#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>


std::string rand_computer_choice(std::string valid_options[6])
{
    int rand_int = rand() % (2 - 0 + 1) + 0;
    std::string computer_play = valid_options[rand_int];
    return computer_play;
}


std::string decide_winner(std::string play_1, std::string play_2)
{    
    std::string winner;

    if ((play_1 == "rock" && play_2 == "scissors") || (play_1 == "scissors" && play_2 == "rock"))
    {
        winner = "rock";
        return winner;
    }else if ((play_1 == "rock" && play_2 == "paper") || (play_1 == "paper" && play_2 == "rock"))
    {
        winner = "paper";
        return winner;
    }else if ((play_1 == "paper" && play_2 == "scissors") || (play_1 == "scissors" && play_2 == "paper"))
    {
        winner = "scissors";
        return winner;
    }
    return "1";
}


std::string format_choise(std::string play_1)
{
    if (play_1 == "1")
    {
        play_1 = "rock";
    }
    else if (play_1 == "2")
    {
        play_1 = "paper";
    }else if (play_1 == "3")
    {
        play_1 = "scissors";
    }
    
    return play_1;
}


int main(int argc, char const *argv[])
{
    std::srand(time(0));

    std::string valid_options[6] = {"rock", "paper", "scissors", "1", "2", "3"};

    char continue_playing;
    do
    {
        system("cls");

        std::string player_choice;
        std::string computer_choice;

        std::cout << "===Rock Paper Scissor Game !!!===" << std::endl;

        std::cout << "\n\n\nDigite o nome ou numero correspondente" << std::endl;
        std::cout << "1.Rock\n2.Paper\n3.Scissors\n";
        
        //generate the computer choise
        computer_choice = rand_computer_choice(valid_options);
        //std::cout << "O computador escolheu: " << computer_choice << std::endl;   //mostra qual a escolha do computador, somente para testes

        //ask for user input of choise
        std::cout << "\nSua escolha: ";
        std::cin >> player_choice;
        //Converts player input to lowercase to compare in valid options
        for (char& i : player_choice)
        {
            i = std::tolower(i);
        }
        
        //check if player_choice exist in the array valid_options        
        std::string* result = std::find(std::begin(valid_options), std::end(valid_options), player_choice);
        if (result == std::end(valid_options))
        {
            std::cout << "Opcao invalida. Pressione qualquer tecla para tentar novamente." << std::endl;
            getch();
            continue;
        }

        //format player choise if choosed 1, 2 or 3.
        player_choice = format_choise(player_choice);

        //check what is the winner choise
        std::string winner = decide_winner(player_choice, computer_choice);

        //check if anyone wins
        if (player_choice == winner)
        {
            std::cout << "\nVoce venceu !!!" << std::endl;
            std::cout << "computador escolheu: " << computer_choice << std::endl;
            std::cout << "voce escolheu: " << player_choice << std::endl;
        }else if (computer_choice == winner)
        {
            std::cout << "\nVoce perdeu." << std::endl;
            std::cout << "computador escolheu: " << computer_choice << std::endl;
            std::cout << "voce escolheu: " << player_choice << std::endl;
        }else
        {
            std::cout << "\nEmpatou !!!" << std::endl;
            std::cout << "computador escolheu: " << computer_choice << std::endl;
            std::cout << "voce escolheu: " << player_choice << std::endl;
        }

        std::cout << "\nDeseja jogar novamente ?(y/n): ";
        std::cin >> continue_playing;

        if (continue_playing == 'n')
        {
            return 0;
        }
        
    } while (true);
    
    return 0;
}
