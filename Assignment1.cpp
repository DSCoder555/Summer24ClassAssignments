#include <iostream>
#include <cmath>
using namespace std;
/**
 * calculateResults function: takes in a string and tries to calculate team scores and determine the winning team
 * @param str: the inputed string of race placements
 * @return: true if str is valid input after displaying score results or false if the input was invalid
*/

bool calculateResults(string str){
    //Finds the size of the team of the first place runner
    int teamSize = 1;
    char base = str[0];
    for (int i = 1; i < str.length(); i++)
    {
        if(str[i]==base) teamSize++;
    }

    //Calculates the number of runners on each team, assumes that each team is even but it will be checked later
    int teams = str.length()/teamSize;

    //Creates arrays to store the number of runners and total runner scores of up to 26 possible teams
    int teamCounts[26] = {0};
    int teamScores[26] = {0};

    //Takes each char from the string and add one to its team's runner count and its position to its team's score
    for (int i = 0; i < str.length(); i++)
    {
        int curr = int(str[i])-65;
        //Checks each char of the string to make sure it is an uppercase letter
        if(curr>25||curr<0){
            cout<<"Invalid input: Your input was invalid."<<endl;
            return false;
        }
        teamCounts[curr]++;
        teamScores[curr] += i+1;
    }

    //Checks each team's number of runners to make sure they are 0(not competing) or teamSize, 
    //making sure all competing teams have the same number of runners
    for(int count : teamCounts){
        if(count != 0 && count != teamSize){
            cout<<"Invalid input: Your teams are not even."<<endl;
            return false;
        }
    }

    //Finds the best team based on which competing team has the lowest score
    int bestTeam = 0;
    for (int i = 1; i < 26; i++)
    {
        if(teamScores[i]>0){
            if (teamScores[i]<teamScores[bestTeam]||teamScores[bestTeam]==0) bestTeam=i;
        }  
    }
    double bestTeamScore = (floor((teamScores[bestTeam]/double(teamSize))*100.0))/100.0;

    //Prints the number of teams and runners on each team
    cout<<"There are "<<teams<<" teams."<<endl;
    cout<<"Each team has "<<teamSize<<" runners."<<endl;

    //Prints the competing team scores in alphabetical order
    cout<<"Team  Score"<<endl;
    for (int i = 0; i < 26; i++)
    {
        if(teamScores[i]==0) continue;
        double score = (floor((teamScores[i]/double(teamSize))*100.0))/100.0;
        cout<<char(i+65)<<"     "<<score<<endl;
    }

    //Prints the previously found best team's name and score
    cout<<"The winning team is Team "<<char(bestTeam+65)<<" with a score of "<<bestTeamScore<<"."<<endl;
    return true;
}

int main(){
    //Asks the user for race results then displays team scores until the user inputs "done" breaking the loop
    string input = "";
    do
    {
        cout<<"Enter the race results: ";
        cin>>input;
        if(input != "done") calculateResults(input);
    } while (input != "done");
    return 0;
}