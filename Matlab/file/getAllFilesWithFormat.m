function fileList = getAllFilesWithFormat(dirName, fmt)
  % based on https://stackoverflow.com/a/2654459
  % usage:
  % files = getAllFilesWithFormat(dirname, '2018*.txt');
  
  if nargin == 2,
     dirsrch = strcat(dirName, '/', fmt);
  else 
     dirsrch =  dirName;
  end
  
  dirData = dir(dirsrch);      %# Get the data for the current directory
  dirIndex = [dirData.isdir];  %# Find the index for directories
  fileList = {dirData(~dirIndex).name}';  %'# Get a list of the files
  if ~isempty(fileList)
    fileList = cellfun(@(x) fullfile(dirName,x),...  %# Prepend path to files
                       fileList,'UniformOutput',false);
  end
  subDirs = {dirData(dirIndex).name};  %# Get a list of the subdirectories
  validIndex = ~ismember(subDirs,{'.','..'});  %# Find index of subdirectories
                                               %#   that are not '.' or '..'
  for iDir = find(validIndex)                  %# Loop over valid subdirectories
    nextDir = fullfile(dirName,subDirs{iDir});    %# Get the subdirectory path
    fileList = [fileList; getAllFilesWithExt(nextDir, ext)];  %# Recursively call getAllFiles
  end

end