
def is_float(value):
  try:
    float(value)
    return True
  except:
    return False


def ShiftWithNewf(arr, n_val, sz):
  arr2 = arr
  for i in range(sz - 1):
    arr2[sz - 1 - i] = arr[sz - 2 - i]

  arr2[0] = n_val

  return arr2



def ShiftWithNewArr1Df(arr, n_val_arr, sz_timestep):
  arr2 = arr

  for i in range(sz_timestep - 1):
    arr2[sz_timestep - 1 - i] = arr[sz_timestep - 2 - i]

  arr2[0] = float(n_val_arr)

  return arr2

def ShiftWithNewArrf(arr, n_val_arr, sz_timestep):
  arr2 = arr
  #print(type(n_val_arr))
  #if isinstance(n_val_arr, float):
  #  dim = 1
  #else:
  dim = len(n_val_arr) #tok

  #print('Dim = {}'.format(dim))

  for j in range(dim):
    for i in range(sz_timestep - 1):
      arr2[j][sz_timestep - 1 - i] = arr[j][sz_timestep - 2 - i]

  for j in range(dim):
    arr2[j][0] = float(n_val_arr[j])

  return arr2

