//
//  MainGameController.h
//  Project Fieldlord
//
//  Created by Jason Fieldman on 2/24/14.
//  Copyright (c) 2014 Jason Fieldman. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MonsterView.h"
#import "MonsterInfo.h"
#import "GameState.h"
#import "HelpView.h"

@interface MainGameController : UIViewController <UIGestureRecognizerDelegate, GKGameCenterControllerDelegate> {

	/* Gesture Pad */
	UIView *_gesturePad;
	
	/* Active monsters */
	NSMutableArray *_activeMonsters;
	
	/* If this is non-zero, don't animate this monster */
	int _dontAnimateIndex;
	
	/* Shotgun */
	BOOL _shotgunArmed;
	
	/* GC crap */
	BOOL _wantsGCShow;
	NSMutableDictionary *_achReport;
	
	/* Views */
	UIView   *_monsterField;
	
	UIView   *_statsView;
	UIImageView *_reticuleView;
	UILabel  *_shotsLabel;
	UILabel  *_scoreLabel;
	
	/* Burst */
	UIImageView *_burstView;
	
	/* Menu */
	UIView   *_menuView;
	
	UIButton *_muteButton;
	UIImageView *_muteXout;
	
	UIButton *_helpButton;
	UIButton *_gcButton;
	UIButton *_restartButton;
	
	UIButton *_shotgunButton;
	CALayer  *_shotgunRingLayer;
	UILabel  *_shotgunCountLabel;
	
	HelpView *_helpView;
	
	/* Who's it? */
	int       _indexIt;
}

@property (nonatomic, readonly) float affinityChance;
@property (nonatomic, readonly) float affinityStrength;
@property (nonatomic, readonly) float fearRadius;
@property (nonatomic, readonly) float fearMultiplier;

SINGLETON_INTR(MainGameController);

- (void) setMonsterCountTo:(int)numMonsters;
- (void) animateMonstersNewPositions;
- (void) animateMonstersToAvoidTouchAt:(CGPoint)point;

- (void) updateStats;
- (void) updateGCStats;

- (int) it;



@end
