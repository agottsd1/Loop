//
//  RileyLink.h
//  RileyLink
//
//  Created by Pete Schwamb on 8/5/14.
//  Copyright (c) 2014 Pete Schwamb. All rights reserved.
//

@import CoreBluetooth;
@import Foundation;

#define RILEYLINK_EVENT_DEVICE_CREATED          @"RILEYLINK_EVENT_DEVICE_CREATED"
#define RILEYLINK_IDLE_RESPONSE_RECEIVED        @"RILEYLINK_IDLE_RESPONSE_RECEIVED"
#define RILEYLINK_EVENT_DEVICE_CONNECTED        @"RILEYLINK_EVENT_DEVICE_CONNECTED"
#define RILEYLINK_EVENT_DEVICE_DISCONNECTED     @"RILEYLINK_EVENT_DEVICE_DISCONNECTED"
#define RILEYLINK_EVENT_DEVICE_ATTRS_DISCOVERED @"RILEYLINK_EVENT_DEVICE_ATTRS_DISCOVERED"
#define RILEYLINK_EVENT_DEVICE_READY            @"RILEYLINK_EVENT_DEVICE_READY"
#define RILEYLINK_EVENT_DEVICE_TIMER_TICK       @"RILEYLINK_EVENT_DEVICE_TIMER_TICK"
#define RILEYLINK_EVENT_RSSI_CHANGED            @"RILEYLINK_EVENT_RSSI_CHANGED"
#define RILEYLINK_EVENT_NAME_CHANGED            @"RILEYLINK_EVENT_NAME_CHANGED"

#define RILEYLINK_SERVICE_UUID          @"0235733b-99c5-4197-b856-69219c2a3845"
#define RILEYLINK_DATA_UUID             @"c842e849-5028-42e2-867c-016adada9155"
#define RILEYLINK_RESPONSE_COUNT_UUID   @"6e6c7910-b89e-43a5-a0fe-50c5e2b81f4a"
#define RILEYLINK_CUSTOM_NAME_UUID      @"d93b2af0-1e28-11e4-8c21-0800200c9a66"
#define RILEYLINK_TIMER_TICK_UUID       @"6e6c7910-b89e-43a5-78af-50c5e2b86f7e"
#define RILEYLINK_FIRMWARE_VERSION_UUID @"30d99dc9-7c91-4295-a051-0a104d238cf2"

@class RileyLinkBLEDevice;

@interface RileyLinkBLEManager : NSObject

@property (nonatomic, nonnull, readonly, copy) NSArray<RileyLinkBLEDevice *> *rileyLinkList;

- (void)connectDevice:(nonnull RileyLinkBLEDevice *)device;
- (void)disconnectDevice:(nonnull RileyLinkBLEDevice *)device;

- (nonnull instancetype)initWithAutoConnectIDs:(nonnull NSSet<NSString *> *)autoConnectIDs;

@property (nonatomic, nonnull, readonly) NSSet<NSString *> *autoConnectIDs;

- (void)setScanningEnabled:(BOOL)scanningEnabled;

/**
 Converts an array of UUID strings to CBUUID objects, excluding those represented in an array of CBAttribute objects.

 @param UUIDStrings An array of UUID string representations to filter
 @param attributes  An array of CBAttribute objects to exclude

 @return An array of CBUUID objects
 */
+ (nonnull NSArray *)UUIDsFromUUIDStrings:(nonnull NSArray *)UUIDStrings excludingAttributes:(nullable NSArray *)attributes;

@end

