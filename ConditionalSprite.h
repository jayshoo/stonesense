#pragma once

#include "BlockCondition.h"

// generic superclass
class SpriteNode
{
	public:
		SpriteNode(void){};
		virtual ~SpriteNode(void){};
	
	// this returns true if the sprite matched, and also adds
	// sprites to the block as required
    virtual bool copyToBlock(Block* b)=0;
    // adds a child if appropriate (vestigial in some cases)
    virtual void addChild(SpriteNode* child){};	
};

// root nesting structure
class RootBlock : public SpriteNode
{
	vector<SpriteNode*> children;
	  
	public:
		RootBlock(void);
		~RootBlock(void); 
	
    bool copyToBlock(Block* b);
    void addChild(SpriteNode* child);	
};

// nesting conditional structure
class SpriteBlock : public ConditionalNode, public SpriteNode
{
	BlockCondition* conditions;
	vector<SpriteNode*> children;
	SpriteNode* elsenode;
	  
	public:
		SpriteBlock(void);
		~SpriteBlock(void);
	
    bool copyToBlock(Block* b);
    bool addCondition(BlockCondition* cond);
    void addChild(SpriteNode* child);
	void addElse(SpriteNode* child);
};

// rotational conditional structure
class RotationBlock : public ConditionalNode, public SpriteNode
{
	vector<SpriteNode*> children;
	  
	public:
		RotationBlock(void);
		~RotationBlock(void);
	
    bool copyToBlock(Block* b);
    bool addCondition(BlockCondition* cond);
    void addChild(SpriteNode* child);
};

// display element
class SpriteElement : public SpriteNode
{
private:

public:
  c_sprite sprite;
  
  SpriteElement(void);
  ~SpriteElement(void){};

  bool copyToBlock(Block* b);
};
