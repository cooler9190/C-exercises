#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

class TeamMember;
class Team;
class TeamMessage;

class Team {
    public:
    Team(const std::string &name);

    std::string getName() const { return m_name; };

    std::vector<std::shared_ptr<TeamMember>> getMembers() const { return m_membersList; };

    void addMember(const std::shared_ptr<TeamMember> &member);

    void removeMember(const std::shared_ptr<TeamMember> &member);

    private:
    std::vector<std::shared_ptr<TeamMember>> m_membersList;
    std::string m_name;
};

class TeamMember : public std::enable_shared_from_this<TeamMember> {
    public:
    TeamMember(const std::string &name);

    std::vector<std::shared_ptr<TeamMessage>> getMessages() const { return m_messages; };

    std::string getName() const { return m_name; };

    std::shared_ptr<Team> getTeam() const { return m_teamPtr; };

    void changeTeam(const std::shared_ptr<Team> &otherTeam);

    void leaveTeam();

    void makeNewTeam(const std::string &name);

    void addMessage(const std::shared_ptr<TeamMessage> &message);

    void forgetMessage();

    void sendMessage();

    private:
    std::vector<std::shared_ptr<TeamMessage>> m_messages;
    std::string m_name;
    std::shared_ptr<Team> m_teamPtr;
};

class TeamMessage {
    public:
    TeamMessage(const std::string &message) : m_message(message) {}

    std::string getMessage() const { return m_message; };

    private:
    std::string m_message;
};

#endif