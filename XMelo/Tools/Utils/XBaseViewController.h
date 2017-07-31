//
//  XBaseViewController.h
//  XMelo
//
//  Created by X.Melo on 2017/7/13.
//  Copyright © 2017年 欣欣然. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XHead.h"

#define xBaseHeadHeight 10.f

@interface XBaseViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>


@property (nonatomic, strong)   UITableView             *tableView;
@property (nonatomic, assign)   UITableViewStyle        tableStyle;
@property (nonatomic, assign)   UITableViewCellStyle    cellStyle;

///包含多少个区 默认为1
@property (nonatomic, assign)   NSInteger  numberOfSections;
///返回每个区多少行
@property (nonatomic, assign)   NSInteger(^numberOfRowsInSection)(NSInteger section);
///设置cell高度
@property (nonatomic, copy)     CGFloat(^heightForRowAtIndexPath)(NSIndexPath *indexPath);

///头部标题
@property (nonatomic, copy)     NSString *(^titleForHeaderInSection)(NSInteger section);
///设置头部高度
@property (nonatomic, copy)     CGFloat(^heightForHeadrAtIndexPath)(NSInteger section);
///设置头部view
@property (nonatomic, copy)     UIView *(^viewForHeaderInSection)(NSInteger section);

///尾部标题
@property (nonatomic, copy)     NSString *(^titleForFooterInSection)(NSInteger section);
///设置尾部高度
@property (nonatomic, copy)     CGFloat(^heightForFooterAtIndexPath)(NSInteger section);
///设置尾部view
@property (nonatomic, copy)     UIView *(^viewForFooterInSection)(NSInteger section);
///创建cell
@property (nonatomic,strong)    UITableViewCell *(^cellForRowAtIndexPath)(UITableView *tableView, NSIndexPath *indexPath);

///下拉head刷新
- (void)updateDataFromHeadWith:(void(^)())block;

///上拉footer加载
- (void)updateDataFromFootWith:(void(^)())block;

- (void)showFooerButtonWithTitle:(NSString *)title clickBlock:(void(^)(UIButton *aButton))aBlock;

/** 设置点击事件 */
@property (nonatomic, copy) void(^didSelectRowAtIndexPath)(NSIndexPath *indexPath);


@end
