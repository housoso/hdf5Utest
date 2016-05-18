from org.csstudio.opibuilder.scriptUtil import PVUtil
from org.eclipse.jface.dialogs import MessageDialog

#filePath = display.getWidget("Text Input").getValue()

#MessageDialog.openInformation(
#            None, "Dialog from Hdf5 Script", "HDF5File says: The File is " + filePath);
##############################################################3





fileName = display.getWidget("Text Input").getValue()


PVUtil.writePV("vs://CODES/test/input",fileName)
PVUtil.writePV("vs://CODES/test/inputtrg",1)








MessageDialog.openInformation(
            None, "Dialog from Hdf5 Script", "HDF5File says: The File is " + fileName);