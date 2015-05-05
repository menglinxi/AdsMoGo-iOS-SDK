//
//  LomarkAdView.h
//
//  Created by DONSON on 14-2-18.
//  Copyright (c) 2014年 donson. All rights reserved.
//

#pragma mark --定义--
//需修改
#define kLomarkAppKey              @"1000"  //appkey
#define kLomarkSecreateKey         @"1000"  //secretkey

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

//是否为ipad
#define isIPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//推荐使用的 banner 类型广告尺寸
#define ADSIZE_1280_200 CGSizeMake(1280, 200)
#define ADSIZE_640_100 CGSizeMake(640, 100)
#define ADSIZE_480_75 CGSizeMake(480, 75)
#define ADSIZE_360_56 CGSizeMake(360, 56)
#define ADSIZE_320_50 CGSizeMake(320, 50)
#define ADSIZE_240_38 CGSizeMake(240, 38)

//浮动窗广告，推荐使用以下两个尺寸
#define FWSIZE_600_500 CGSizeMake(600, 500)
#define FWSIZE_300_250 CGSizeMake(300, 250)

typedef NS_ENUM(NSInteger, LomarkAdType)
{
    LomarkAdTypeBanner      = 1,     //横幅广告
    LomarkAdTypeFloatWindow = 2,     //插屏广告
    LomarkAdTypeFullScreen  = 3      //全屏广告
};

//应用分类信息
//1工具 2游戏 3阅读 4娱乐 5商旅 6财经 7汽车
//8女性（母婴 服饰 时尚） 9新闻 10生活 11体育 12其他
typedef NS_ENUM(NSInteger, AppCategory)
{
    AppTool = 1,
    AppGame ,
    AppReading ,
    AppEntertainment ,
    AppBusinessTravel ,
    AppFinance ,
    AppCars ,
    AppFemale ,
    AppNews ,
    AppLive ,
    AppSports ,
    AppOther
};


#pragma mark --LomarkAdView.h--

@protocol LomarkAdViewDelegate;
@interface LomarkAdView : UIView

@property (nonatomic, assign) id <LomarkAdViewDelegate> delegate;
@property (nonatomic, retain) UIViewController *rootViewController;

/**
 @功能: 初始化广告
 @注意: autoTimeInterval属性仅在LomarkAdTypeBanner类型时有效，并且时间为 15~60s，不在此范围内的一律设置为15s
 @参数: AdType:广告类型 appCategory:应用类型 size:广告视图的size autoTimeInterval:每隔一段时间刷新一次广告（仅LomarkAdTypeBanner有效）
 */
- (id)initWithAdType:(LomarkAdType)type appCategory:(AppCategory)appCategory appId:(NSString *)theAppId appKey:(NSString *)theAppKey appSecret:(NSString *)theAppSecret appName:(NSString *)appName size:(CGSize)size autoTimeInterval:(int)time;

//获取 SDK 版本号
+(NSString *)getLomarkSDKVersion;

//设置是否每隔一段时间自动刷新 banner 广告。  默认为YES，自动刷新。
- (void)enableBannerAutoInsterval:(BOOL)enable;

//设置是否开启调试模式。 默认为关闭
+ (void)enableDebugMode:(BOOL)enabled;

//设置是否开启地理位置采集。 默认为开启
+ (void)enableLocation:(BOOL)enabled;

@end


#pragma mark --LomarkAdViewDelegate--

@protocol LomarkAdViewDelegate <NSObject>
@optional

//即将请求广告数据
- (void)adViewWillLoadAd:(UIView *)view;

//--展示回调--
- (void)adViewDidLoadAd:(UIView *)view;

//--错误回调--
- (void)adView:(UIView *)view didFailToReceiveAdWithError:(NSError *)error;

//--点击回调--
-(void)adViewDidClicked:(UIView *)view;

//视图被移除
-(void)adViewDidRemoved:(UIView *)view;

//分享
-(void)adShareAction:(UIView *)view Info:(NSDictionary *)infoDict;

@end

