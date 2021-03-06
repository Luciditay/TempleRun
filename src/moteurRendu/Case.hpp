#include <glm> 

class Case
{
public:
    virtual void dessinerCase() const = 0; //Méthode virtuelle pure

};

class CaseTerrain : protected Case //Case de base, sans saut ni trou
{
public:
    CaseTerrain(const glm::vec4 VertexHG, const glm::vec4 VertexHD, const glm::vec4 VertexBG, glm::vec4 VertexBD) 
    : m_VertexHG(VertexHG), 
      m_VertexHD(VertexHD), 
      m_VertexBG(VertexBG), 
      m_VertexBD(VertexBD)  {}

    ~CaseTerrain();
    void dessinerCase();

private:
    glm::vec4 m_VertexHG = {0, 0, 0, 1}; //Les quatres coins de la case
    glm::vec4 m_VertexHD = {0, 0, 0, 1};
    glm::vec4 m_VertexBG = {0, 0, 0, 1};
    glm::vec4 m_VertexBD = {0, 0, 0, 1};

};

class CaseMur : protected Case
{
public:
    CaseMur()
    ~CaseMur();
    void dessinerCase();

private:
    float hauteurMur;

}