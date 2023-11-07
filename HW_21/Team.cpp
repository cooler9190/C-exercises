#include "Team.hpp"

Team::Team(const std::string &name) : m_name(name) {}

void Team::addMember(const std::shared_ptr<TeamMember> &member) {
    m_membersList.push_back(member);
}

void Team::removeMember(const std::shared_ptr<TeamMember> &member) {
    auto iter = std::find_if(m_membersList.begin(), m_membersList.end(), [&](const std::shared_ptr<TeamMember> &val) { 
        return val->getName() == member->getName(); });

    m_membersList.erase(iter);
}

TeamMember::TeamMember(const std::string &name) : m_name(name) {}

void TeamMember::changeTeam(const std::shared_ptr<Team> &otherTeam) {
    if(this->m_teamPtr) {
        this->m_teamPtr->removeMember(shared_from_this());
    }

    this->m_teamPtr = otherTeam;
    otherTeam->addMember(shared_from_this());
    std::cout << this->m_name << " joined Team" << std::endl;
}

void TeamMember::leaveTeam() {
    if (auto currentTeam = this->m_teamPtr) {
        currentTeam->removeMember(shared_from_this());
    }
    this->m_teamPtr.reset();
}

void TeamMember::makeNewTeam(const std::string& name) {
    auto newTeam = std::make_shared<Team>(name);
    changeTeam(newTeam);
}

void TeamMember::addMessage(const std::shared_ptr<TeamMessage>& message) {
    this->m_messages.push_back(message);
}

void TeamMember::sendMessage() {
    if (this->m_messages.empty()) {
        return;
    }
 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, this->m_messages.size() - 1);
 
    size_t randomIndex = dist(gen);
    auto randomMessage = this->m_messages[randomIndex];
 
    if (auto currentTeam = m_teamPtr) {
        for (const auto& member : currentTeam->getMembers()) {
            member->addMessage(randomMessage);
        }
    }
    std::cout << "Member shared the message!" << std::endl;
}

void TeamMember::forgetMessage() {
    if (!this->m_messages.empty()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dist(0, this->m_messages.size() - 1);
 
        size_t randomIndex = dist(gen);
        this->m_messages.erase(this->m_messages.begin() + randomIndex);
        std::cout << "Member forgot the message!" << std::endl;
    } else {
        return;
    }
}