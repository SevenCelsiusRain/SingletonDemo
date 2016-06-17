//
//  ViewController.m
//  SingletonDemon
//
//  Created by SevenCelsius on 16/6/15.
//  Copyright © 2016年 SevenCelsius. All rights reserved.
//

#import "ViewController.h"
#import "Try.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    Try *first = [Try sharemyTry];
    Try *twoTry = [[Try alloc] init];
    Try *thirdTry = [twoTry copy];
    Try *forthTry = [twoTry mutableCopy];
    
    NSLog(@"%@, %@, %@, %@", first, twoTry, thirdTry, forthTry);
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
