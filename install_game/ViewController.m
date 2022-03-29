//
//  ViewController.m
//  install_game
//
//  Created by apple on 2021/6/29.
//

#import "ViewController.h"
#import <UIKit/UIKit.h>
#import <mach-o/dyld.h>
#import "MyViewController.h"
@interface ViewController ()

@end

@implementation ViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
//    int count = _dyld_image_count();
//
//    for (int i = 0; i < count; i++) {
//
//        NSLog(@"%s",_dyld_get_image_name(i));
//    }
    
}

- (IBAction)pushClick:(UIButton *)sender {
    
    MyViewController *editHead = [[MyViewController alloc] init];
    //设置待显示控制器的范围
    [editHead.view setFrame:CGRectMake(0, 0, 173, 108)];
    //设置待显示控制器视图的尺寸
    editHead.preferredContentSize = CGSizeMake(173, 108);
    UIPopoverController *popover = [[UIPopoverController alloc] initWithContentViewController:editHead];
    
    //设置弹出窗口尺寸
    popover.popoverContentSize = CGSizeMake(173, 108);
    [popover presentPopoverFromRect:CGRectMake(0, 200, 173, 108) inView:self.view permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    
    
}

@end
