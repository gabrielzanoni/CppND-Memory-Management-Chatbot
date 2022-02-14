#include <iostream>
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    ////
    //// EOF STUDENT CODE
}

GraphNode::GraphNode(const GraphNode &source)
{
    std::cout << "GraphNode: COPYING content of instance " << &source << " to instane " << this << std::endl;

    for (auto it = std::begin(source._childEdges); it != std::end(source._childEdges); ++it) {
        GraphEdge node = *(*it);
        _childEdges.push_back(std::move(std::make_unique<GraphEdge>(node.GetID())));
    }

    _parentEdges = source._parentEdges;
    _chatBot = std::move(source._chatBot);
    _id = source._id;
    _answers = source._answers;
}

GraphNode& GraphNode::operator=(const GraphNode &source)
{
    std::cout << "GraphNode: ASSIGNING content of instance " << &source << " to instane " << this << std::endl;

    if (this == &source) {
        return *this;
    }

    _childEdges.clear();
    _parentEdges.clear();
    _answers.clear();
    _id = 0;

    for (auto it = std::begin(source._childEdges); it != std::end(source._childEdges); ++it) {
        GraphEdge node = *(*it);
        _childEdges.push_back(std::move(std::make_unique<GraphEdge>(node.GetID())));
    }

    _parentEdges = source._parentEdges;
    _chatBot = std::move(source._chatBot);
    _id = source._id;
    _answers = source._answers;

    return *this;
}

GraphNode::GraphNode(GraphNode &&source)
{
    std::cout << "GraphNode: MOVING (constructor) content of instance " << &source << " to instane " << this << std::endl;

    for (auto it = std::begin(source._childEdges); it != std::end(source._childEdges); ++it) {
        GraphEdge node = *(*it);
        _childEdges.push_back(std::move(std::make_unique<GraphEdge>(node.GetID())));
    }

    _parentEdges = source._parentEdges;
    _chatBot = std::move(source._chatBot);
    _id = source._id;
    _answers = source._answers;

    source._childEdges.clear();
    source._parentEdges.clear();
    source._answers.clear();
    source._id = 0;
}

GraphNode& GraphNode::operator=(GraphNode &&source)
{
    std::cout << "GraphNode: MOVING (assignment) content of instance " << &source << " to instane " << this << std::endl;

    if (this == &source) {
        return *this;
    }

    _childEdges.clear();
    _parentEdges.clear();
    _answers.clear();
    _id = 0;

    for (auto it = std::begin(source._childEdges); it != std::end(source._childEdges); ++it) {
        GraphEdge node = *(*it);
        _childEdges.push_back(std::move(std::make_unique<GraphEdge>(node.GetID())));
    }

    _parentEdges = source._parentEdges;
    _chatBot = std::move(source._chatBot);
    _id = source._id;
    _answers = source._answers;

    source._childEdges.clear();
    source._parentEdges.clear();
    source._answers.clear();
    source._id = 0;

    return *this;
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(std::weak_ptr<GraphEdge> edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
