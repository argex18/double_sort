from traceback import print_exc

def double_sort(list1, list2, remove_duplicates=False):
    try:
        # list to return
        sorted_list = []

        if not isinstance(list1, list) or not isinstance(list2, list):
            raise TypeError('error: list 1 and list 2 must be two lists of integers')

        # sorting list1 in ascending order
        list1.sort()

        # sorting list2 in ascending order
        list2.sort()

        # union sorting algorithm
        n = 0
        p = 0
        saving_point = None
        while n <= len(list1):
            # if list 2 > list1
            if n == len(list1):
                while p < len(list2):
                    sorted_list.append( list2[p] )
                    p += 1
                break
            # if list 1 > list2
            if p == len(list2):
                while n < len(list1):
                    sorted_list.append( list1[n] )
                    n += 1
                break

            if saving_point and int( list1[n] ) < int( list2[saving_point] ):
                sorted_list.append( list1[n] )
            elif saving_point and int( list1[n] ) >= int( list2[saving_point] ):
                
                sorted_list.append( list2[saving_point] )
                # resetting the saving_point
                saving_point = None
                p += 1
                continue
            else:
                while p < len(list2):
                    if int( list2[p] ) < int( list1[n] ):
                        sorted_list.append( int(list2[p]) )
                    else:
                        sorted_list.append( int(list1[n]) )
                        saving_point = p
                        break
                    p += 1
            print( sorted_list )
            n += 1
        print ( sorted_list )

        if remove_duplicates:
            # removing duplicates from sorted_list
            sorted_list = list( set(sorted_list) )

        # returning sorted_list
        return sorted_list
    except Exception:
        print_exc()
        return []