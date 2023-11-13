class Entity
{
  public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;

  private:
    sf::Vector2f mVelocity;
}

/*class SceneNode
{
public:
    typedef std::unique_pyr<SceneNode> Ptr;
    SceneNode() : mParent(nullptr), mChildren() {}
private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);
}*/


class SceneNode : public sf::Transformable, public sf::Drawable,
 private sf::NonCopyable
{
 public:
    typedef std::unique_ptr<SceneNode> Ptr;
    SceneNode();
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);
 private:
    virtual void draw(sf::RenderTarget& target,
    sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target,
    sf::RenderStates states) const;
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
 };