//
//  DDGSearchController.h
//  DuckDuckGo2
//
//  Created by Chris Heimark on 12/9/11.
//  Copyright (c) 2011 DuckDuckGo, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DDGSearchHandler.h"

typedef enum {
	DDGSearchControllerStateHome = 0,
	DDGSearchControllerStateWeb
} DDGSearchControllerState;

@class DDGSearchSuggestionsProvider, DDGHistoryProvider, DDGAddressBarTextField, DDGInputAccessoryView;
@interface DDGSearchController : UIViewController<UITextFieldDelegate, UINavigationControllerDelegate> {
    NSString *oldSearchText;
    BOOL barUpdated;
    BOOL autocompleteOpen;
    BOOL backButtonVisible;
    
    UIButton *stopOrReloadButton;
    DDGInputAccessoryView *inputAccessory;
    NSRange currentWordRange;
    NSMutableArray *unusedBangButtons;
}

@property (nonatomic, weak) IBOutlet DDGAddressBarTextField *searchField;
@property (nonatomic, weak) IBOutlet UIButton *leftButton;
@property (weak, nonatomic) IBOutlet UIButton *actionButton;
@property (weak, nonatomic) IBOutlet UIButton *cancelButton;
@property (nonatomic, weak) IBOutlet UIView *background;
@property (nonatomic, weak) IBOutlet UIView *searchBar;
@property (nonatomic, strong) UIViewController *contentController;

-(IBAction)leftButtonPressed:(UIButton*)sender;
-(IBAction)actionButtonPressed:(id)sender;
-(IBAction)cancelButtonPressed:(id)sender;

@property(nonatomic, strong) UINavigationController *autocompleteNavigationController;
@property(nonatomic, assign) DDGSearchControllerState state;
@property(nonatomic, weak, readonly) id<DDGSearchHandler> searchHandler;

-(id)initWithSearchHandler:(id <DDGSearchHandler>)searchHandler;

// managing the search controller
-(void)updateBarWithURL:(NSURL *)url;
-(void)clearAddressBar;
-(void)dismissAutocomplete;

// the web view needs to call these at the appropriate times
-(void)webViewStartedLoading;
-(void)webViewFinishedLoading;
-(void)setProgress:(CGFloat)progress;
-(void)webViewCanGoBack:(BOOL)canGoBack;

// helper methods
-(NSString *)validURLStringFromString:(NSString *)urlString;
-(BOOL)isQuery:(NSString *)queryOrURL;
-(NSString *)queryFromDDGURL:(NSURL *)url;

@end