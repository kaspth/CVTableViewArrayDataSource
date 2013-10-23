//
//  CVTableViewArrayDataSource.h
//
//  Created by Kasper Timm on 11/09/13.
//  Copyright (c) 2013 Kasper Timm Hansen. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^CVConfigureTableViewCellHandler)(id cell, id object);
typedef void(^CVTableViewRowAtIndexPathHandler)(NSIndexPath *indexPath, id object);
typedef UITableView *(^CVDequeueFromTableViewHandler)(UITableView *tableView);
typedef BOOL(^CVCanEditRowAtIndexPathHandler)(NSIndexPath *indexPath, id object);

@interface CVTableViewArrayDataSource : NSObject <UITableViewDataSource, UITableViewDelegate>

///@brief Set this to an array of NSStrings for the section titles
///@discussion Setting this changes the expectations to what is in the objects array.
///@see objects
@property (nonatomic, strong) NSArray *sections;

///@brief YES if headers should be hidden, NO otherwise. Default is NO.
///@discussion Handy when a search result returns no matches, and no table headers should be shown.
@property (nonatomic) BOOL hideHeadersForEmptySections;

///@brief The data objects the cells display
///@discussion If sections are set this should be an array with the number of sections other arrays in it. Those arrays have the objects for a section.
@property (nonatomic, strong) NSArray *objects;
@property (nonatomic, copy) NSString *cellIdentifier;

@property (nonatomic, copy) CVConfigureTableViewCellHandler cellConfigurationHandler;

///@brief The block to call when a row is selected
///@discussion if not set, the row will be deselected automatically.
@property (nonatomic, copy) CVTableViewRowAtIndexPathHandler didSelectRowHandler;

///@brief Use this to act as the delegate of a tableView which doesn't have a reference to the cell with the passed in cellIdentifier.
///@discussion Ideal for UISearchResultsDataSource to reuse the cells from another tableView.
@property (nonatomic, copy) CVDequeueFromTableViewHandler dequeueFromTableViewHandler;

///@brief YES if objects are a mutable array, NO otherwise.
///@discussion Set to NO if data source shouldn't support editing.
@property (nonatomic) BOOL objectsAreEditable;

@property (nonatomic, copy) CVCanEditRowAtIndexPathHandler canEditRowHandler;

///@brief Called if the data source supports editing and the user deleted a row.
@property (nonatomic, copy) CVTableViewRowAtIndexPathHandler didDeleteRowHandler;

- (instancetype)initWithTableView:(UITableView *)tableView;

///@param objects Passing a mutable array makes the table view data source support deletion of rows.
///@discussion Override objectsAreEditable if this automatic behavior is not wanted.
- (instancetype)initWithTableView:(UITableView *)tableView objects:(NSArray *)objects;

- (void)reloadVisibleCells;

@end
