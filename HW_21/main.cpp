#include "Team.hpp"

int main() {
    std::shared_ptr<TeamMember> member1 = std::make_shared<TeamMember>("Nick");
    std::shared_ptr<TeamMember> member2 = std::make_shared<TeamMember>("Marry");
    std::shared_ptr<TeamMember> member3 = std::make_shared<TeamMember>("Lincoln");
 
    member1->makeNewTeam("Team A");
    std::cout << member1->getTeam()->getName() << std::endl;
 
    member2->changeTeam(member1->getTeam());
    member3->changeTeam(member1->getTeam());

    std::shared_ptr<TeamMessage> message1 = std::make_shared<TeamMessage>("Hello, Code Academy!");
    std::shared_ptr<TeamMessage> message2 = std::make_shared<TeamMessage>("What's up?");
 
    member1->addMessage(message1);
    std::cout << message1->getMessage() << std::endl;
    member2->addMessage(message2);
    std::cout << message2->getMessage() << std::endl;
 
    member1->sendMessage();
    member2->sendMessage();
    member3->sendMessage();
 
    member1->forgetMessage();
    member2->forgetMessage();

    return 0;
}