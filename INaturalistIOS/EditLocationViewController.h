//
//  EditLocationController.h
//  INaturalistIOS
//
//  Created by Ken-ichi Ueda on 2/28/12.
//  Copyright (c) 2012 iNaturalist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

@class EditLocationViewController;
@class CrossHairView;
@class INatLocation;

@protocol EditLocationViewControllerDelegate <NSObject>
@optional
- (void)editLocationViewControllerDidCancel:(EditLocationViewController *)controller;
- (void)editLocationViewControllerDidSave:(EditLocationViewController *)controller location:(INatLocation *)location;
@end

@interface EditLocationViewController : UIViewController <MKMapViewDelegate>
@property (weak, nonatomic) UIViewController *delegate;
@property (weak, nonatomic) IBOutlet MKMapView *mapView;
@property (strong, nonatomic) INatLocation *currentLocation;
@property (strong, nonatomic) UIBarButtonItem *currentLocationButton;
@property (strong, nonatomic) UIBarButtonItem *mapTypeButton;
@property (weak, nonatomic) IBOutlet CrossHairView *crossHairView;

- (IBAction)clickedCancel:(id)sender;
- (IBAction)clickedDone:(id)sender;
- (void)clickedCurrentLocationButton;
- (void)clickedMapTypeButton;

- (void)updateCrossHair;
- (double)degreesToMeters:(double)degrees;
- (double)metersToDegrees:(double)meters;
@end

@interface INatLocation : NSObject
@property (nonatomic, strong) NSNumber *latitude;
@property (nonatomic, strong) NSNumber *longitude;
@property (nonatomic, strong) NSNumber *accuracy;
@property (nonatomic, strong) NSDate *updatedAt;
- (id)initWithLatitude:(NSNumber *)latitude longitude:(NSNumber *)longitude accuracy:(NSNumber *)accuracy;
@end